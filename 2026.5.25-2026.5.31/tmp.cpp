#include<bits/stdc++.h>
using namespace std;
#define int long long
using ull=unsigned long long;
using ll=long long;
using db=double;
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
const int Size=(1<<20)+1;
char buf[Size],*p1=buf,*p2=buf,buffer[Size];
int op1=-1;
const int op2=Size-1;
inline char readchar(){
    if(p1!=p2)return *p1++;
    return p1==(p2=(p1=buf)+fread(buf,1,Size-1,stdin))?EOF:*p1++;
}
inline void flush(){fwrite(buffer,1,op1+1,stdout),op1=-1;}
inline void writechar(const char &x){if(op1==op2)flush();buffer[++op1]=x;}
#ifndef ONLINE_JUDGE
#define readchar getchar
#endif
#define putchar writechar
inline int read() {    
    int s=1,c=readchar(),x=0;    
    while(c<=32)c=readchar();if(c=='-')s=-1,c=readchar();
    for(;('0'<=c && c<='9');c=readchar())x=x*10+c-'0';
    return x*s;
}
int p;
inline void print(long long x){
    if(x<0)writechar('-'),x=-x;
    char s[30];int n=0;
    while(x||!n)s[n++]='0'+x%10,x/=10;
    while(n--)writechar(s[n]);
}
const int N=5e5+5,M=1e3+5,inf=1e18,mod=1e9+7,K=1e6+5,P=13331;
int n,i,a[N],j,k,l,T,m,c,fl,q,f[N][3];
vector<int> g[N];
inline void dfs(int u,int fa){
    if(u!=1&&g[u].size()==1){
        f[u][0]=0;
        f[u][1]=1;
        f[u][2]=inf;
        return;
    }
    int c0=0,c1=0,mn=inf;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        c0+=f[v][0];c1+=min(f[v][1],f[v][2]);
        mn=min(mn,f[v][1]-f[v][0]);
    }
    f[u][0]=c1;
    f[u][1]=1+c0;
    f[u][2]=c0+3+mn;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    n=read();
    fu(i,1,n-1){
        int x,y;
        x=read();y=read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    cout<<n*n-min({f[1][0],f[1][1],f[1][2]});
    return 0;
}