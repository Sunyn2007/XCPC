#include <bits/stdc++.h>
using namespace std;
const int N=100;
int T,i,j,k,a[N][N],n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=0;
        if(k<n||n*n-n+1<k){
            cout<<"No\n";
            continue;
        }
        set<int> s;
        for(i=1;i<=n*n;i++)s.insert(i);
        for(i=1;i<=n;i++){
            a[i][i]=k+i-1;
            s.erase(k+i-1);
        }
        for(i=1;i<=n;i++)for(j=1;j<=n;j++){
            if(a[i][j])continue;
            a[i][j]=*s.begin();s.erase(*s.begin());
        }
        cout<<"Yes\n";
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}