#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
using ll=long long;
using db=double;
const int N=5e5+5;
int n,m,vis[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    fu(i,1,m){
        int x,y;
        cin>>x>>y;
        if(y==x+1){
            vis[x]=1;
        }
    }
    fu(i,1,n-1){
        if(!vis[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}