/*
Your task is to count for k=1,2,....,n the number of ways two knights can be placed on a k*k chessboard so that they do not attack each other.

Input
The only input line contains an integer n.

Output
Print n integers: the results.

Constraints
1<=n<=10000

Example

Input:
8

Output:
0
6
28
96
252
550
1056
1848
*/

/*
===================== INTUITION ========================
Here’s the intuition for the Two Knights problem:

- For a k x k chessboard, you want to count the number of ways to place two knights so that they do not attack each other.
- The total number of ways to place two knights is: C(k*k, 2) = (k*k) * (k*k - 1) / 2
- Knights attack each other only if they are placed so that one can reach the other in a single move. For each 2x3 or 3x2 rectangle on the board, there are 2 pairs of knights that attack each other.
- The number of such attacking pairs is: 4 * (k-1) * (k-2)
- So, the answer for each k is: (k*k * (k*k - 1) / 2) - 4 * (k-1) * (k-2)
- You loop from k = 1 to n and print the result for each.
*/ 

#include <iostream>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(long long k = 1; k <= n; k++){
        long long total_pairs = k * k * (k * k - 1) / 2; // Total ways to place two knights
        long long attacking_pairs = 0;
        if(k > 2){
            attacking_pairs = 4 * (k-1) * (k-2); // Possible Pairs that attack each other
        }
        long long non_attacking_pairs = total_pairs - attacking_pairs; // Non-attacking pairs
        cout << non_attacking_pairs << endl;
    }
        
    return 0;
}