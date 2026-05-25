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
inline void print(long long x) {
	if(x<0)writechar('-'),x=-x;
	char s[30];int n=0;
	while(x||!n)s[n++]='0'+x%10,x/=10;
	while(n--)writechar(s[n]);
}
const int N=5e5+5,M=1e3+5,inf=1e18,mod=998244353,K=1e6+5,P=13331;
int n,i,j,k,l,r,T,m,x,ans,f[N],h[N],smx[N],smn[N];
vector<int> g[N];
int c1,c2;
inline void init(int u){
    smn[u]=inf;
    if(g[u].size()==0){
        smx[u]=smn[u]=u;
        return;
    }
    for(auto v:g[u]){
        init(v);
        smx[u]=max(smx[u],smx[v]);
        smn[u]=min(smn[u],smn[v]);
    }
}
inline void dfs(int u,int x){
    if(g[u].size()==0){
        if(u<=x)c1=min(c1,f[u]);
        else c2=min(c2,h[u]);
        return ;
    }
    int cnt0=0,cnt1=0;
    for(auto v:g[u]){
        if(smx[v]>x) cnt0++;
        if(smn[v]<=x) cnt1++;
    }
    for(auto v:g[u]){
        f[v]=f[u]+cnt0-(smx[v]>x);
        h[v]=h[u]+cnt1-(smn[v]<=x);
        dfs(v,x);   
    }
}
inline int ck(int x){
    fu(i,0,n)f[i]=h[i]=0;
    c1=c2=inf;
    dfs(1,x);
    return c1<=c2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    n=read();
    fu(i,2,n){
        int x=read();
        g[x].push_back(i);
    }
    int l=1,r=n;
    int ans=0;
    init(1);
    while(l<=r){
        int mid=l+r>>1;
        if(ck(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
	return 0; 
}