#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Size=(1<<20)+1;
char buf[Size],*p1=buf,*p2=buf,buffer[Size];
int op1=-1;
const int op2=Size-1;
inline char readchar(){
    if(p1!=p2) {
        return *p1++;
    }
    return p1==(p2=(p1=buf)+fread(buf,1,Size-1,stdin))?EOF:*p1++;
}
inline void flush(){
    fwrite(buffer,1,op1+1,stdout),op1=-1;
}
inline void writechar(const char &x) {
    if(op1==op2) flush();
    buffer[++op1]=x;
}
#ifndef ONLINE_JUDGE
#define readchar getchar
#endif
#define putchar writechar
inline int read() {    
    int s=1,c=readchar(),x=0;    
    while(c<=32) {
        c=readchar();
    }
    if(c=='-') {
        s=-1,c=readchar();
    }
    for(; ('0'<=c && c<='9'); c=readchar()) {
        x=x*10+c-'0';
    }
    return x*s;
}
inline void print(long long x) {
    if(x<0) {
        writechar('-'),x=-x;
    }
    char s[25];
    int n=0;
    while(x||!n) {
        s[n++]='0'+x%10,x/=10;
    }
    while(n--) {
        writechar(s[n]);
    }
}
const int N=5e5+5,M=1e3+5,inf=1e15;
int n,i,j,k,l,r,T,deg[N],m,f[N];
string s;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        s=' '+s;
        vector<int> a(n+5,0),b(n+5,0);
        int ca=0,cb=0;
        for(i=n;i>=1;i--){
            if(s[i]=='1'){
                if(ca<=cb){
                    ca++;
                    a[ca]=1;
                }
                else {
                    cb++;
                    b[cb]=1;
                }
            }
            else{
                if(ca<=cb)cb++;
                else ca++;
            }
        }
        int tmp=0;
        vector<int> ans;
        for(i=1;i<=max(ca,cb);i++){
            if(a[i]+b[i]+tmp>=2){
                ans.push_back((a[i]+b[i]+tmp)%2);
                tmp=1;
            }
            else{
                ans.push_back(a[i]+b[i]+tmp);
                tmp=0;
            }
        }
        if(tmp)ans.push_back(1);
        reverse(ans.begin(),ans.end());
        int t=0;
        while(ans[t]==0&&t!=ans.size()-1)t++;
        for(i=t;i<=ans.size()-1;i++)cout<<ans[i];
        cout<<'\n';
    }
    return 0;
}