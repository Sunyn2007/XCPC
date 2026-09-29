#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
#define fu(a,b,c) for(int a=b;a<=c;a++)
inline int pw(int a,int k){
    int ans=1;
    while(k){
        if(k&1)ans=ans*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int ans=1;
    int tmp=26;
    fu(i,1,m){
        if(n>=tmp){
            ans=ans+tmp;
            tmp=tmp*26;
        }
        else{
            ans=ans+(m-i+1)*n;break;
        }
    }
    cout<<ans%mod<<' ';
    ans=1;tmp=1;
    fu(i,1,m){
        tmp=tmp*26%mod;
        int cnt=1-pw((1-pw(tmp,mod-2)+mod)%mod,n);
        cnt=(cnt+mod)%mod;
        cnt=cnt*tmp%mod;
        ans=(ans+cnt)%mod;
    }
    cout<<ans;
    return 0;
}