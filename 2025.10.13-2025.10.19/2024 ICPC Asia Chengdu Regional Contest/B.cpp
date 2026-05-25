#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=305,mod=1e9+7;
int T,n,i,j,k,l,o,p,fl,q,pre[N],a[N],f[N][N][N][3],sm[N][N][N];//i a b- 
string s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>T;
    cin>>s;
    for(i=1;i<=n;i++){
        if(s[i-1]=='?')a[i]=-1;
        else a[i]=s[i-1]-'a';
    }
    for(i=1;i<=n;i++)pre[i]=pre[i-1]+(a[i]==-1);
    if(a[1]==-1){
        f[1][1][0][0]=1;
        f[1][0][1][1]=1;
        f[1][0][0][2]=1;
    }
    else f[1][0][0][a[1]]=1;
    for(i=2;i<=n;i++){
        for(int x=0;x<=pre[i];x++){
            for(int y=0;x+y<=pre[i];y++){
                if(a[i]==-1){
                    if(x)f[i][x][y][0]=(f[i-1][x-1][y][1]+f[i-1][x-1][y][2])%mod;
                    if(y)f[i][x][y][1]=(f[i-1][x][y-1][0]+f[i-1][x][y-1][2])%mod;
                    if(pre[i]-x-y)f[i][x][y][2]=(f[i-1][x][y][0]+f[i-1][x][y][1])%mod;
                }
                else{
                    for(int t=0;t<3;t++){
                        if(t==a[i])continue;
                        f[i][x][y][a[i]]=(f[i][x][y][a[i]]+f[i-1][x][y][t])%mod;
                    }
                }
            }
        }
    }
    for(int x=0;x<=pre[n];x++){
        for(int y=0;y+x<=pre[n];y++){
            sm[x][y][pre[n]-x-y]=(f[n][x][y][0]+f[n][x][y][1]+f[n][x][y][2])%mod;
        }
    }
    for(i=0;i<=300;i++){
        for(j=0;j<=300;j++){
            for(k=0;k<=300;k++){
                if(i)sm[i][j][k]+=sm[i-1][j][k];
                if(j)sm[i][j][k]+=sm[i][j-1][k];
                if(k)sm[i][j][k]+=sm[i][j][k-1];
                if(i&&j)sm[i][j][k]-=sm[i-1][j-1][k];
                if(k&&j)sm[i][j][k]-=sm[i][j-1][k-1];
                if(i&&k)sm[i][j][k]-=sm[i-1][j][k-1];
                if(i&&j&&k)sm[i][j][k]+=sm[i-1][j-1][k-1];
                sm[i][j][k]=(sm[i][j][k]%mod+mod)%mod;
            }
        }
    }
    while(T--){
        int x,y,z;
        cin>>x>>y>>z;
        cout<<sm[x][y][z]<<'\n';
    }
    return 0;
}