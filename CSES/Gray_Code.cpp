/*
A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

Your task is to create a Gray code for a given length n.

Input
The only input line has an integer n.

Output
Print 2^n lines that describe the Gray code. You can print any valid solution.

Constraints
1<=n<=16

Example

Input:
2

Output:
00
01
11
10
*/ 

#include <iostream>
#include <bitset>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int total = 1 << n; // 2^n
    for(int i=0; i<total; i++){
        int gray = i ^ (i >> 1); // Convert to Gray code using the formula: G(i) = i ^ (i >> 1)
        cout<< bitset<16>(gray).to_string().substr(16 - n) << endl; // Print the Gray code as a binary string of length n
    }
        
    return 0;
}