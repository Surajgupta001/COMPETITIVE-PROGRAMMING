/*
Byteland is a beautiful land known because of its beautiful trees.

Misha has found a binary tree with n vertices, numbered from 1 to n. A binary tree is an acyclic connected bidirectional graph containing n vertices and n−1 edges. Each vertex has a degree at most 3, whereas the root is the vertex with the number 1 and it has a degree at most 2.

Unfortunately, the root got infected.

The following process happens n times:

==> Misha either chooses a non-infected (and not deleted) vertex and deletes it with all edges which have an end in this vertex or just does nothing.
Then, the infection spreads to each vertex that is connected by an edge to an already infected vertex (all already infected vertices remain infected).

==> As Misha does not have much time to think, please tell him what is the maximum number of vertices he can save from the infection (note that deleted vertices are not counted as saved).

Input
There are several test cases in the input data. The first line contains a single integer t (1≤t≤5000) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains one integer n (2≤n≤3⋅10^5) — the number of vertices of the tree.

The i-th of the following n−1 lines in the test case contains two positive integers ui and vi (1≤ui,vi≤n), meaning that there exists an edge between them in the graph.

It is guaranteed that the graph is a binary tree rooted at 1. It is also guaranteed that the sum of n over all test cases won't exceed 3⋅10^5.

Output
For each test case, output the maximum number of vertices Misha can save.

Example

Input
4
2
1 2

4
1 2
2 3
2 4

7
1 2
1 5
2 3
2 4
5 6
5 7

15
1 2
2 3
3 4
4 5
4 6
3 7
2 8
1 9
9 10
9 11
10 12
10 13
11 14
11 15

Output
0
2
2
10

Note
In the first test case, the only possible action is to delete vertex 2, after which we save 0 vertices in total.

In the second test case, if we delete vertex 2, we can save vertices 3 and 4.
*/

/*
Problem: Given a binary tree rooted at 1, the root is infected. Each turn, you can delete a non-infected vertex (removing its subtree), then the infection spreads to all adjacent vertices. Find the maximum number of vertices you can save from infection.

Approach: Use DFS and DP to compute, for each subtree, the maximum number of vertices that can be saved if you delete one of its children.
*/

/*
Code Explanation
- Variables
    - tree: Adjacency list representing the tree.
    - subtree_size[node]: Number of nodes in the subtree rooted at node.
    - max_saved[node]: Maximum number of vertices that can be saved in the subtree rooted at node.

DFS Function
    - For each node, recursively compute the size of its subtree and the maximum number of vertices that can be saved.
    
    - For each child, consider the scenario where you delete that child (and its subtree), thus saving all its descendants (except the child itself).
    
    - The DP transition is: `max_saved[node] = max(max_saved[node], sum_saved_children - max_saved[child] + subtree_size[child] - 1)`, where:;
        - `sum_saved_children`: Total saved vertices from all children.
        - `max_saved[child]`: Saved vertices from the child being deleted (since its subtree is deleted, these are not saved).
        - `subtree_size[child] - 1`: All nodes in the deleted child's subtree except the child itself.
*/  

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree(300005); // Adjacency list for the tree
int subtree_size[300005];         // subtree_size[node]: size of subtree rooted at node
int max_saved_dp[300005];         // max_saved_dp[node]: max vertices saved in subtree rooted at node (DP array)

// DFS to compute subtree sizes and DP values
void dfs(int node, int parent) {
    // Initializing the subtree size for the current node
    subtree_size[node] = 1;
    
    // Initializing the max saved DP for the current node
    max_saved_dp[node] = 0;

    int sum_saved_children = 0;

    // Traverse all children
    for (auto child : tree[node]) {
        if (child == parent) continue; // Skip the parent to avoid cycles
        dfs(child, node);
        sum_saved_children += max_saved_dp[child]; // Sum of saved vertices from children
        subtree_size[node] += subtree_size[child]; // Update the size of the current subtree
    }

    // Try deleting each child and see how many vertices can be saved
    for (auto child : tree[node]) {
        if (child == parent) continue;
        // Save all vertices in the deleted child's subtree except the child itself
        // plus the saved vertices from other children
        max_saved_dp[node] = max(max_saved_dp[node], sum_saved_children - max_saved_dp[child] + subtree_size[child] - 1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            tree[i].clear(); // Clear the adjacency list for each test case
            subtree_size[i] = 0; // Reset subtree sizes
            max_saved_dp[i] = 0; // Reset DP values
        }

        // Build the tree
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs(1, 0); // Start DFS from root (1), parent is 0 (non-existent)
        cout << max_saved_dp[1] << endl;
    }
}

