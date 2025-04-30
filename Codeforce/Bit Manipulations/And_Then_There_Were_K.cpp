#include <iostream>
using namespace std;

// TLE 
// void solve(){
//     long long n;
//     cin>>n;

//     long long x = n;

//     while(x > 0){
//         n = n - 1;
//         x = x & n;
//     }
//     cout<<n<<endl;
// }

void solve(){
    long long n;
    cin>>n;

    int count = 0;

    while(n > 0){
        n = n >> 1; // Right shift by 1 bit
        count++;
    }
    
    int result = (1 << (count - 1)) - 1; // Left shift by (count - 1) bits and subtract 1
    cout<<result<<endl;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}