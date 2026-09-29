#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
inline int pw(int a,int k){
    int ans=1;
    while(k){
        if(k&1)ans=ans*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return (ans+mod)%mod;
}
int T;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int V=pw(2,m);
        int ans=0;
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        if(n&1){
            //ans=(-1*pw((1-V+mod)%mod,n/2)+mod)%mod;
            ans=(ans+pw(V-1,n-1))%mod;
        }
        else{
            ans=(-(V-1)*pw((1-V+mod)%mod,n/2-1)%mod+mod)%mod;
            ans=(ans+pw(V-1,n-1))%mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}