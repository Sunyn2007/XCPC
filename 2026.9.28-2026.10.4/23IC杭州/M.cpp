#include <bits/stdc++.h>
using namespace std;
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define int long long
const int N=5e5+5;
int T,a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        int n,tmp,sum=0;
        int s=0,s1=0,s2=0;
        cin>>n;
        fu(i,1,n)cin>>a[i];
        fu(i,1,n){
            s+=a[i];
            if(i>1&&i<n){
                if(a[i]<a[i+1]&&a[i]<a[i-1])
                    tmp=i;
            }
        } 
        fu(i,1,tmp+1)s1+=a[i];
        fu(i,tmp-1,n)s2+=a[i];
        cout<<fixed<<setprecision(15)<<max({(double)s/n,(double)s1/(tmp+1),(double)s2/(n-tmp+2)})<<'\n';
    }
    return 0;
}