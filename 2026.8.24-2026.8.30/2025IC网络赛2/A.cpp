#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
using ll=long long;
using db=double;
const int mod=998244353;
int T;
struct vec{
    int x,y;
    vec(int _=0,int __=0):x(_),y(__){};
    vec operator-(const vec&other)const{
        return {x-other.x,y-other.y};
    }
    vec operator+(const vec&other)const{
        return {x+other.x,y+other.y};
    }
    int operator&(const vec&other)const{
        return x*other.x+y*other.y;
    }
    int operator*(const vec&other)const{
        return x*other.y-y*other.x;
    }
    int len(){
        return x*x+y*y;
    }
};
inline int cmp(vec x,vec y){
    if(x.x==y.x)return x.y<y.y;
    return x.x<y.x;
}
inline vector<vec> hull(vector<vec> &p){
    int n=p.size()-1;
    int top=0;
    sort(p.begin()+1,p.end(),cmp);
    vector<int> vis(n+1),stk(n+5);
    stk[++top]=1;
    fu(i,2,n){
        while(top>=2&&((p[stk[top]]-p[stk[top-1]])*(p[i]-p[stk[top]]))<=0)vis[stk[top--]]=0;
        vis[i]=1;stk[++top]=i;
    }
    int tmp=top;
    fd(i,n-1,1){
        if(vis[i])continue;
        while(top>tmp&&((p[stk[top]]-p[stk[top-1]])*(p[i]-p[stk[top]]))<=0)vis[stk[top--]]=0;
        vis[i]=1;stk[++top]=i;
    }
    vector<vec> as;
    fu(i,1,top)as.push_back(p[stk[i]]);
    return as;
}
inline int area(const vector<vec> &p){
    int n=p.size()-1;
    __int128 ans=0;
    fu(i,1,n){
        ans=ans+(__int128)(p[i]*p[i-1]);
    }
    //ans=ans+(p[1]*p[n]);
    if(ans<0)ans=-ans;
    return ans;
}
inline db Len(const vector<vec> &p){
    int n=p.size()-1;
    db ans=0;
    fu(i,1,n){
        ans=ans+sqrt(1.0*(p[i]-p[i-1]).len());
    }
    return ans;
}
const db pi=acos(-1);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        int n,r2,r3;
        cin>>n>>r2>>r3;
        vector<vec> p(n+1);
        fu(i,1,n){
            int x,y;
            cin>>x>>y;
            p[i]={x,y};
        }
        p=hull(p);
        db l=Len(p);
        db A=area(p)*0.5+l*r2+pi*r2*r2;
        db ans=A*2*r3+0.5*pi*r3*r3*(l+2*pi*r2)+4.0/3.0*pi*r3*r3*r3;
        cout<<fixed<<setprecision(15)<<ans<<'\n';
    }
    return 0;
}