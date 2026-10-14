#include <bits/stdc++.h>
using namespace std;
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define int long long
const int N=2.5e5+5,mod=1e9+7,inf=1e10;
int n,q,a[N],c[N];
vector<int> g[N];
bitset<N> x,y,z,f[19];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    fu(i,1,n){
        cin>>a[i]>>c[i];
        g[c[i]].push_back(i);
        x.set(a[i]);
    }
    fu(i,1,n){
        for(auto x:g[i])y.set(a[x]);
        z=x^y;
        for(auto x:g[i])f[__lg(x)]|=(z>>a[x]);
        for(auto x:g[i])y[a[x]]=0;
    }
    while(q--){
        int ans=0;
        int d;
        cin>>d;
        fu(i,0,18){
            if(f[i][d]){
                ans=(1<<i);break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}