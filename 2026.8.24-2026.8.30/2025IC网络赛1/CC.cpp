#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
using ll=long long;
using db=double;
const int N=1e6+5,inf=1e18;
int T;
struct nd{
    int l,r;
}a[N];
map<int,int> mp;
inline int find(int x){
    if(mp[x]==0)return x;
    return mp[x]=find(mp[x]); 
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        mp.clear();
        int n,m;
        cin>>m>>n;
        fu(i,1,m){
            cin>>a[i].l>>a[i].r;
        }
        auto cmp=[](nd x,nd y){
            if(x.r==y.r)return x.l<y.l;
            return x.r<y.r;
        };
        sort(a+1,a+m+1,cmp);
        fu(i,1,m){
            if(find(a[i].l)!=a[i].r){
                n--;
                mp[find(a[i].l)]=find(a[i].l)+1;
            }
        }
        cout<<n<<'\n';
    }
    return 0;
}