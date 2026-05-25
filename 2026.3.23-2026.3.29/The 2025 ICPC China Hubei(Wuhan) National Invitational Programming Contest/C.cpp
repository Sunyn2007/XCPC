#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N];
int i,j,k,l,o,p,T,n,m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)cin>>a[i];
        int t=2*n-1;
        vector<int> ans(m+5),f1(m+5),f2(m+5),f3(m+5);
        for(i=1;i<=n;i++){
            int k=a[i]/t,r=a[i]%t;
            if(k>m){
                ans[1]++;continue;
            }
            if(i==n){
                f1[k]++;continue;
            }
            int s1=2*(n-i),s2=2*i-1;
            if(r>=s1)f1[k]++;
            else if(r<s1&&r<s2)f2[k]++;
            else ans[1]++,f3[k]++;
        }
        for(i=0;i<=m;i++){
            for(j=1;j<=m;j+=(i+1))ans[j]+=f1[i];
            for(j=1;j<=m;j+=(2*i+1))ans[j]+=f2[i];
            for(j=1+i;j<=m;j+=(2*i+1))ans[j]+=f2[i];
            for(j=1+i;j<=m;j+=(i+1))ans[j]+=f3[i];
        }
        for(i=1;i<=m;i++)cout<<ans[i]<<' ';
        cout<<'\n'; 
    }
    return 0;
}