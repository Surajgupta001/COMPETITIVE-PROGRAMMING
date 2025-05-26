/*
Your task is to calculate the number of trailing zeros in the factorial n!.

For example, 20! = 2432902008176640000 and it has 4 trailing zeros.

Input
The only input line has an integer n.

Output
Print the number of trailing zeros in n!.

Constraints
1<=n<=10^9

Example
Input:
20

Output:
4
*/

#include <iostream>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    long long countZeros = 0;
    for(long long i = 5; n / i> 0; i *= 5){ // so, (n / i) counts how many times the factor 5 (and its higher powers) appear in the numbers from 1 to n.
        countZeros += n / i; // Count how many multiples of 5, 25, 125, etc. are in n
    }

    cout << countZeros << endl;
    return 0;
}