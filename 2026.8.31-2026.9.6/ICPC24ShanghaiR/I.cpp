#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
const int N=5e5+5,mod=998244353;
int n,i,j,k,a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        fu(i,1,n)cin>>a[i];
        auto cmp=[](int x,int y){
            return x>y;
        };
        sort(a+1,a+n+1,cmp);
        if(a[1]==0){
            cout<<0<<'\n';
            continue;
        }
        a[n+1]=0;
        int tmp=1;
        while(tmp<=n&&a[tmp])tmp++;
        tmp--;
        int cnt=(tmp-1)/(k-1);
        tmp=cnt*(k-1);
        int ans=a[1]%mod;
        fu(i,2,tmp+1)ans=ans*a[i]%mod;
        cout<<ans<<'\n';
    }
    return 0;
}