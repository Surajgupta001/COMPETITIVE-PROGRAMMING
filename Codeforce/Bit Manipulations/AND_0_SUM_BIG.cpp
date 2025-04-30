#include <iostream>
using namespace std;

// 1st Approach - Using Power Function, Modulo And Recursion  
int m = 1e9 + 7;
int powerMod(long long a, long long b, long long m) {
    if(b == 0) return 1;
    if(b == 1) return a;

    // Recursive
    long long half = powerMod(a, b / 2, m) % m;
    long long result = 0;

    if(b % 2 == 0) {
        result = (half%m * half%m) % m;
    } else {
        result = (half%m * half%m * a) % m;
    }
    
    return result;
}

void solve(){
    long long n, k;
    cin>>n>>k;

    cout<<powerMod(n, k, m)<<endl;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}

// 3rd Approach - Using Iterative Method
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long num = 1, mod = 1000000007;
        for (int i = 0; i < k; ++i) {
            num = (num * n) % mod;
        }
        cout << num << endl;
    }
    return 0;
}