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