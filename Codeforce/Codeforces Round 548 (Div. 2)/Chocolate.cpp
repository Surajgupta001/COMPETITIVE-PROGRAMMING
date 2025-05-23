/*
You went to the store, selling n types of chocolates. There are ai chocolates of type i in stock.

You have unlimited amount of cash (so you are not restricted by any prices) and want to buy as many chocolates as possible. However if you buy xi chocolates of type i (clearly, 0≤xi≤ai), then for all 1≤j<i at least one of the following must hold:

xj=0 (you bought zero chocolates of type j)
xj<xi (you bought less chocolates of type j than of type i)

For example, the array x=[0,0,1,2,10] satisfies the requirement above (assuming that all ai≥xi), while arrays x=[0,1,0], x=[5,5] and x=[3,2] don't.

Calculate the maximum number of chocolates you can buy.

Input
The first line contains an integer n (1≤n≤2⋅105), denoting the number of types of chocolate.

The next line contains n integers ai (1≤ai≤109), denoting the number of chocolates of each type.

Output
Print the maximum number of chocolates you can buy.

Examples

Input
5
1 2 1 3 6

Output
10

Input
5
3 2 5 4 10

Output
20
InputCopy
4
1 1 1 1

Output
1
Note
In the first example, it is optimal to buy: 0+0+1+3+6 chocolates.

In the second example, it is optimal to buy: 1+2+3+4+10 chocolates.

In the third example, it is optimal to buy: 0+0+0+1 chocolates.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    ll prev = v[n - 1]; // Start with the last type
    ans += prev;

    for (int i = n - 2; i >= 0; i--) {
        // The number of chocolates for type i must be less than or equal to prev - 1
        ll current = min(v[i], prev - 1);
        if (current < 0) current = 0; // Ensure we don't go negative
        ans += current;
        prev = current;
    }

    cout << ans << endl;

    return 0;
}