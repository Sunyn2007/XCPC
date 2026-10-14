#include <bits/stdc++.h>
using namespace std;
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define int long long
const int N=5e5+5,mod=1e9+7,inf=1e10;
int T,a[N],b[N],w[N],fac[N],inv[N],n;
vector<int> g[N];
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
    cin>>T;
    fac[0]=inv[0]=1;
    fu(i,1,N-5)fac[i]=fac[i-1]*i%mod,inv[i]=pw(fac[i],mod-2);
    while(T--){
        cin>>n;
        fu(i,1,n)
            g[i].clear();
        fu(i,1,n)cin>>a[i];
        fu(i,1,n)cin>>b[i];
        fu(i,1,n)cin>>w[i];
        queue<int> q;
        vector<int> dis(n+5,inf);
        fu(i,1,n){
            if(a[i]<a[b[i]])q.push(i),dis[i]=1;
            g[b[i]].push_back(i);
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto v:g[u]){
                if(dis[u]+1<dis[v]&&a[v]<a[u]+w[u]){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        fu(i,1,n){
            if(a[i]<a[b[i]])cout<<(a[i]+w[i])%mod<<' ';
            else if(dis[i]==inf)cout<<a[i]<<' ';
            else cout<<(a[i]+w[i]*inv[dis[i]]%mod)%mod<<' ';
        }
        cout<<'\n';
    }
    return 0;
}