/*
Your task is to calculate the number of bit strings of length n.

For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input
The only input line has an integer n.

Output
Print the result modulo 10^9+7.

Constraints
1<=n<=10^6

Example
Input:
3

Output:
8
*/ 

#include <iostream>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    long long mod = 1e9 + 7;

    long long result = 1;
    for(int i=1; i <= n; ++i) {
        result = (result * 2) % mod; // Each bit can be either 0 or 1, hence multiplying by 2
    }
    cout << result << endl;

    return 0;
}