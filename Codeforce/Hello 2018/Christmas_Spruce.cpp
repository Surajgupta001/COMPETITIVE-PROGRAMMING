/*
Consider a rooted tree. A rooted tree has one special vertex called the root. All edges are directed from the root. Vertex u is called a child of vertex v and vertex v is called a parent of vertex u if there exists a directed edge from v to u. A vertex is called a leaf if it doesn't have children and has a parent.

Let's call a rooted tree a spruce if its every non-leaf vertex has at least 3 leaf children. You are given a rooted tree, check whether it's a spruce.

The definition of a rooted tree can be found here.

Input
The first line contains one integer n — the number of vertices in the tree (3 ≤ n ≤ 1 000). Each of the next n - 1 lines contains one integer pi (1 ≤ i ≤ n - 1) — the index of the parent of the i + 1-th vertex (1 ≤ pi ≤ i).

Vertex 1 is the root. It's guaranteed that the root has at least 2 children.

Output
Print "Yes" if the tree is a spruce and "No" otherwise.

Output
Print "Yes" if the tree is a spruce and "No" otherwise.

Examples

Input
4
1
1
1
Output
Yes

Input
7
1
1
1
2
2
2
Output
No

Input
8
1
1
1
1
3
3
3
Output
Yes
*/

#include <iostream>
#include <vector>
using namespace std;

// Constants
const int MIN_LEAF_CHILDREN = 3;

// Function to check if a tree is a spruce
bool isSpruce(const vector<int>& parentIndices, const vector<int>& isNonLeaf, int n) {
    bool flag = true;
    vector<int> result(n + 1);
    
    // Count leaf children for each node
    for (int i = 2; i <= n; i++) {
        if (!isNonLeaf[i]) {
            result[parentIndices[i]]++;
        }
    }
    
    // Check if each non-leaf node has at least MIN_LEAF_CHILDREN leaf children
    for (int i = 1; i <= n; i++) {
        if (isNonLeaf[i] && result[i] < MIN_LEAF_CHILDREN) {
            flag = false;
            break;
        }
    }
    
    return flag;
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Input parent indices and mark non-leaf nodes
    vector<int> parentIndices(n + 1);
    vector<int> isNonLeaf(n + 1);
    for (int i = 2; i <= n; i++) {
        int temp;
        cin >> temp;
        parentIndices[i] = temp;
        isNonLeaf[temp]++;
    }
    
    // Check if the tree is a spruce
    if (isSpruce(parentIndices, isNonLeaf, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}