#include<bits/stdc++.h>
using namespace std;
#define int long long
using ull=unsigned long long;
using ll=long long;
using db=double;
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
const int N=5e5+5,M=1e3+5,inf=1e18,mod=1e9+7,K=1e6+5,P=13331;
int i,j,k,l,T,c,a[N];
int n,m;
vector<int> g[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        vector<int> vis(n+5),cnt(n+5),can(n+5);
        queue<int> q;
        fu(i,1,n)g[i].clear();
        fu(i,1,m){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        fu(i,1,k){
            int x;
            cin>>x;vis[x]=1;
            q.push(x);
        }
        while(!q.empty()){
            int u=q.front();
            for(auto v:g[u]){
                cnt[v]++;
                if(cnt[v]==2)q.push(v);
            }
            q.pop();
        }
        fu(i,1,n)cerr<<cnt[i]<<' ';
        cerr<<'\n';
        vector<int> as;
        fu(i,1,n){
            if(!vis[i]&&cnt[i])as.push_back(i);
        }
        cout<<as.size()<<'\n';
        for(auto x:as)cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}