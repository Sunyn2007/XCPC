#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
using ll=long long;
using db=double;
const int N=1e6+5,inf=1e18;
int n,m,f[N][4],a[N];
vector<int> g[N];
inline void dfs(int u,int fa){
    f[u][0]=0;f[u][1]=a[u];
    f[u][2]=-a[u];
    f[u][3]=-inf;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        int f0=f[u][0],f1=f[u][1],f2=f[u][2],f3=f[u][3];
        int tmp=max(f[v][0],f[v][3]);
        f[u][0]=f0+tmp;
        f[u][1]=max(f1+tmp,f0+f[v][1]);
        f[u][2]=max(f2+tmp,f0+f[v][2]);
        f[u][3]=max({f3+tmp,f0+f[v][3],f1+f[v][2],f2+f[v][1]});
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    fu(i,1,n)cin>>a[i];
    fu(i,1,n-1){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    cout<<f[1][3];
    return 0;
}