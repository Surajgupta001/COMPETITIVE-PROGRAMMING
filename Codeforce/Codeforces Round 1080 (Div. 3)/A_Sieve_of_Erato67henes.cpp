/*
A. Sieve of Erato67henes
-----------------------------

You are given n positive integers a1,a2,…,an.

Please determine if it is possible to select any number of elements in a, so that their product is 67.

Note that you may not select zero elements, as the product of zero elements is not defined in this problem.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10^4). The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤5).

The second line of each test case contains n positive integers a1,a2,…,an (1≤ai≤67).

Output
If it is possible to select elements so that their product is 67, output "YES" on one line. Otherwise, output "NO" on one line.

You can output the answer in any case. For example, the strings "yEs", "yes", and "Yes" will also be recognized as positive responses.

Example
Input
2
5
1 7 6 7 67
5
1 3 5 7 8

Output
YES
NO

Note
In the first test case, you can select a1 and a5 to get a1⋅a5=1⋅67=67.

In the second test case, it is impossible to select any number of elements so that their product is 67.
*/

#include <iostream>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        bool found = false;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 67) found = true;
        }

        cout << (found ? "YES" : "NO") << '\n';
    }
}
