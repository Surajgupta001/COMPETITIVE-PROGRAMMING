/*
Roger has p unit-length segments and q L-shaped pieces, each formed by joining two unit-length segments at a right angle.

He wants to use all of these pieces, with no piece left unused, to form a grid of dimensions n×m.

Given p and q, determine whether there exist positive integers n and m such that an n×m grid can be formed using exactly p unit-length segments and q L-shaped pieces, possibly rotating them, and provide any valid n and m.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows.

The first line of each test case contains two integers p and q (1≤p,q≤10^8).

Output
For each test case, print any valid n and m such that it's possible to construct n×m using all pieces. If there are no such n and m, print −1.

Example

Input
7
1 2
1 3
5 1
2 5
2 10
100000000 100000000
1 1

Output
-1
1 2
1 2
2 2
2 4
-1
-1

Note
Here are the constructions for examples 2, 3, and 4. We use a different color for different L-shaped pieces, black for all unit-length segments.
*/

#include <iostream>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        
    int t;
    
    if (cin >> t) {
        while(t--){
            long long p, q;
            cin >> p >> q;
            
            long long S = p + 2 * q;
            long long target = 2 * S + 1;
            
            bool found = false;
            
            // We want to find a, b >= 3 odd integers such that a * b = target
            for (long long d = 3; d * d <= target; d += 2) {
                if (target % d == 0) {
                    long long a = d;
                    long long b = target / d;
                    
                    long long n = (a - 1) / 2;
                    long long m = (b - 1) / 2;

                    // No of horizontal segments needed = n * (m + 1)
                    // No of vertical segments needed = m * (n + 1)
                    long long horizontal = n * (m + 1);
                    long long vertical = m * (n + 1);
                    
                    if (q <= horizontal && q <= vertical) {
                        cout << n << " " << m << "\n";
                        found = true;
                        break;
                    }
                }
            }
            
            if (!found) {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}