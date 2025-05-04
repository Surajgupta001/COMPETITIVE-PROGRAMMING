/*
Theofanis really likes sequences of positive integers, thus his teacher (Yeltsa Kcir) gave him a problem about a sequence that consists of only special numbers.

Let's call a positive number special if it can be written as a sum of different non-negative powers of n. For example, for n=4 number 17 is special, because it can be written as 40+42=1+16=17, but 9 is not.

Theofanis asks you to help him find the k-th special number if they are sorted in increasing order. Since this number may be too large, output it modulo 109+7.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first and only line of each test case contains two integers n and k (2≤n≤109; 1≤k≤109).

Output
For each test case, print one integer — the k-th special number in increasing order modulo 109+7.

Example
InputCopy
3
3 4
2 12
105 564

OutputCopy
9
12
3595374

Note
For n=3 the sequence is [1,3,4,9...]
*/ 


#include <iostream>
#include <algorithm>
using namespace std;

long long M = 1e9 + 7;
string decimalToBinary(long long n){
    string binary = "";

    while(n > 0){
        int remainder = n % 2;
        binary += to_string(remainder);
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int binaryToDecimal(string binary, long long m){
    long long decimal = 0; // Fixed the cursor position
    long long base = 1; // Initialize base value to 1, i.e., 2^0

    int len = binary.length();
    for(int i = len - 1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += base;
            decimal %= M; // Apply modulo operation to keep the result within bounds
        }
        base *= m; // Update base to the next power of m
        base %= M; // Apply modulo operation to keep the result within bounds
    }
    return decimal;
}

void solve(){
    long long n,k;
    cin>>n>>k;

    string binary = decimalToBinary(k);

    long long ans = binaryToDecimal(binary, n);

    cout<<ans<<endl;
    
}

int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}