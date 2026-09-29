#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
const int N=5e5+5,mod=998244353,Lm=2e18+5;
int n,i,j,k,a[N],b[N],c[N];
inline int cmp(int x,int y){
    return x>y;
}
inline int ck(int mid){
    vector<int> g,h;
    int tmp=0;
    fu(i,1,n){
        if(a[i]==0)tmp+=(b[i]>=mid);
        if(a[i]>0){
            if ((mid - b[i]) % a[i] == 0) g.push_back((mid - b[i]) / a[i]);
            else {
                if (mid - b[i] > 0) g.push_back((mid - b[i]) / a[i] + 1);
                else g.push_back((mid - b[i]) / a[i]);
            }
        } 
        if(a[i]<0) {
            if ((mid - b[i]) % a[i] == 0) h.push_back((mid - b[i]) / a[i]);
            else {
                if (mid - b[i] > 0) h.push_back((mid - b[i]) / a[i] - 1);
                else h.push_back((mid - b[i]) / a[i]);
            }
        }
    }
    sort(g.begin(),g.end(),cmp);
    sort(h.begin(),h.end());
    int t=1;
    for(auto v:h){
        if(c[t]<=v){
            tmp++; t++;
        }
    }
    t=n;
    for(auto v:g){
        if(c[t]>=v){
            tmp++; t--;
        }
    }
    return tmp>=(n+1)/2;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--){
        cin>>n;
        fu(i,1,n)cin>>a[i];
        fu(i,1,n)cin>>b[i];
        fu(i,1,n)cin>>c[i];
        int l=-Lm,r=Lm;
        int ans=0;
        sort(c+1,c+n+1);
        while(l<=r){
            int mid=l+r>>1;
            if(ck(mid))ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}