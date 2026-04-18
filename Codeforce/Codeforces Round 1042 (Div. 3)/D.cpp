/*
D. Arboris Contractio

Kagari is preparing to archive a tree, and she knows the cost of doing so will depend on its diameter∗. To keep the expense down, her goal is to shrink the diameter as much as possible first. She can perform the following operation on the tree:

Choose two vertices s and t. Let the sequence of vertices on the simple path† from s to t be v0,v1,…,vk, where v0=s and vk=t.

Remove all edges along the path. In other words, remove edges (v0,v1),(v1,v2),…,(vk−1,vk).

Connect vertices v1,v2,…,vk directly to v0. In other words, add edges (v0,v1),(v0,v2),…,(v0,vk).

It can be shown that the graph is still a tree after the operation.

Help her determine the minimum number of operations required to achieve the minimal diameter.

∗The diameter of a tree is the longest possible distance between any pair of vertices. The distance itself is measured by the number of edges on the unique simple path connecting them.

†A simple path is a path between two vertices in a tree that does not visit any vertex more than once. It can be shown that the simple path between any two vertices is always unique.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains one integer n (2≤n≤2⋅105) — the number of the vertices in the tree.

The following n−1 lines of each test case describe the tree. Each of the lines contains two integers u and v (1≤u,v≤n, u≠v) that indicate an edge between vertex u and v. It is guaranteed that these edges form a tree.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output one integer — the minimum number of operations to minimize the diameter.

Example

Input
4
4
1 2
1 3
2 4
2
2 1
4
1 2
2 3
2 4
11
1 2
1 3
2 4
3 5
3 8
5 6
5 7
7 9
7 10
5 11

Output
1
0
0
4

Note
In the first test case, the diameter of the original tree is 3. Kagari can perform an operation on s=3 and t=4. As the figure depicts, the operations includes the following steps:

Remove edges (3,1), (1,2) and (2,4).
Add edges (3,1), (3,2) and (3,4).

After the operation, the diameter reduces to 2. It can be shown that 2 is the minimum diameter.

In the second test case, the diameter of the tree is 1. It can be shown that 1 is already the minimum, so Kagari can perform no operation.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1, 0);

        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++deg[u]; ++deg[v];
        }

        // Count total leaves
        int L = 0;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 1) ++L;
        }

        // Count how many leaf neighbors each node has
        vector<int> leafAdj(n + 1, 0);
        for (int v = 1; v <= n; ++v) {
            for (int u : adj[v]) {
                if (deg[u] == 1) ++leafAdj[v];
            }
        }

        // Best choice of center maximizes leafAdj[v] + (deg[v]==1)
        int best = 0;
        for (int v = 1; v <= n; ++v) {
            best = max(best, leafAdj[v] + (deg[v] == 1 ? 1 : 0));
        }

        int ans = L - best; // minimal operations to reach diameter 2 (or 0 if n=2)
        cout << ans << '\n';
    }
    return 0;
}

