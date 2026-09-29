#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5e5+5;
int n,m,siz[N],vis[N],ans;
#define fu(a,b,c) for(int a=b;a<=c;a++)
vector<int> g[N];
inline void dfs(int u,int fa){
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    if(vis[u]){
        ans+=(siz[u]+1)/2;
        if(siz[u]%2==1 && fa) vis[fa]=1;
        siz[u]=0;
    }
    else siz[u]++;
}
signed main() {
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        ans=0;
        vector<int> a(m+1);
        fu(i,1,n)siz[i]=0,g[i].clear(),vis[i]=0; 
        fu(i,1,m){
            cin>>a[i];
            vis[a[i]]=1;
        }
        fu(i,1,n-1){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(a[1],0);
        cout<<ans<<'\n';
    }
    return 0;
}