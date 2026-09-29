#include <bits/stdc++.h>
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
const int N=5e5+5,mod=998244353;
int n,a[N];
inline int pw(int a,int k){
    int ans=1;
    while(k){
        if(k&1)ans=ans*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return ans;
}
int p0,p1;
inline int dfs(int x,int y){
    int d=abs(x-y)/min(x,y);
    if(y<=0)return 1;
    if(x<=0)return 0;
    if(x==y)return p0;
    if(x<y){
        return pw(p0,d+1)*dfs(x,y-(d+1)*x)%mod;
    }
    if(x>y){
        int tmp=(pw(p1,d+1)-1+mod)%mod*pw((p1-1+mod)%mod,mod-2)%mod*p0%mod;
        return (tmp+pw(p1,d+1)*dfs(x-(d+1)*y,y)%mod)%mod;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        int a,b,n;
        cin>>a>>b>>n;
        p0=a*pw((a+b)%mod,mod-2)%mod;
        p1=(1-p0+mod)%mod;
        cout<< dfs(x,y) << '\n';
    }
    return 0;
}