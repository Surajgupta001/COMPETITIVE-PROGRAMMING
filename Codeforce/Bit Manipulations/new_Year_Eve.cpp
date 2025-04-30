#include <iostream>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n,k;
    cin>>n>>k;

    long long ans = 1;

    if(k == 1){
        cout<<n<<endl;
    }
    else{
        while(ans < n){
            ans = ans * 2;
            ans = ans + 1;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}