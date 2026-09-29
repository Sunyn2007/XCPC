#include <bits/stdc++.h>
using namespace std;
#define int __int128
using db=double;
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
const int N=5e5+5,mod=998244353,Lm=2e18+5;
int n,i,j,k;
struct vec{
    int x,y;
    vec(int _=0,int __=0): x(_),y(__){};
    inline vec operator-(const vec&other)const{
        return {x-other.x,y-other.y};
    }
    inline vec operator+(const vec&other)const{
        return {x+other.x,y+other.y};
    }
    inline int operator&(const vec&other)const{
        return x*other.x+y*other.y;
    }
    inline int operator*(const vec&other)const{
        return x*other.y-y*other.x;
    }
    inline int len(){
        return x*x+y*y;
    }
};
inline int cmp(vec x,vec y){
    if(x.x==y.x)return x.y<y.y;
    return x.x<y.x;
}
inline vector<vec> hull(vector<vec> &p){
    if(p.size()<=2){
        cout<<"probably";exit(0);
    }
    int n=p.size()-1;
    int top=0;
    sort(p.begin()+1,p.end(),cmp);
    vector<int> vis(n+1),stk(n+5);
    stk[++top]=1;
    fu(i,2,n){
        while(top>=2&&(p[stk[top]]-p[stk[top-1]])*(p[i]-p[stk[top]])<=0)
            vis[stk[top--]]=0;
        vis[i]=1;stk[++top]=i;
    }
    int tmp=top;
    fd(i,n-1,1){
        if(vis[i])continue;
        while(top>tmp&&(p[stk[top]]-p[stk[top-1]])*(p[i]-p[stk[top]])<=0)
            vis[stk[top--]]=0;
        vis[i]=1;stk[++top]=i;
    }
    vector<vec> as;
    fu(i,1,top)as.push_back(p[stk[i]]);
    return as;
}
inline int in(const vec&p,vector<vec> &A){
    int fl=0;
    int n=A.size();
    fu(i,0,n-2){
        vec a=A[i],b=A[i+1];
        int tmp=(p-a)*(p-b);
        if(tmp==0&&((p-a)&(p-b))<=0){
            return 2;
        }
        if(a.y>b.y)swap(a,b);
        if(p.y>=a.y&&p.y<b.y){
            if((a-p)*(b-p)>0)fl^=1;
        }
    }
    return fl;
}
db get_angle(vec P, vec A, vec B) {
    vec PA = A - P;
    vec PB = B - P;
    double angle = atan2((long long)(PA * PB), (long long)(PA & PB));
    return abs(angle);
}
int in_circumcircle(vec A, vec B, vec C, vec D) {
    int cross_ABC = (B - A) * (C - A);
    if (cross_ABC == 0) return 0; 
    vec ad = A - D;
    vec bd = B - D;
    vec cd = C - D;
    int det =  ad.len() * (bd * cd)
                  - bd.len() * (ad * cd)
                  + cd.len() * (ad * bd);
    if(det==0) return 2;
    if (cross_ABC > 0)
        return det >= 0;
    else 
        return det <= 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    signed xxx;
    cin>>xxx;
    n=xxx;
    vector<tuple<int,int,int>> a;
    int mx=-1;
    fu(i,1,n){
        signed x,y,z;
        cin>>x>>y>>z;
        a.push_back({x,y,z});
        mx=max(mx,(int)z);
    }
    vector<vec> A,B;
    for(auto [x,y,z]:a){
        if(z==mx||z==0)B.push_back({x,y});
        else A.push_back({x,y});
    }
    if(A.size()==0){
        cout<<"probably";return 0;
    }
    if(A.size()==1){
        vector<vec> tt;
        tt.push_back({0,0});
        for(auto x:B)tt.push_back(x);
        tt=hull(tt);
        int op=in(A[0],tt);
        if(op==0||op==2){
            cout<<"probably";return 0;
        }
        else cout<<"not a penguin";
    }
    else if(A.size()==2){
        vec P=A[0],Q=A[1];
        auto cmp=[&](vec x,vec y){
            return get_angle(x,P,Q)<get_angle(y,P,Q);
        };
        sort(B.begin(),B.end(),cmp);
        int fl=0;
        for(auto t:B){
            if(!in_circumcircle(P,Q,B[0],t)){
                fl=1;break;
            }
        }
        if(fl)cout<<"not a penguin";
        else cout<<"probably";
    }
    else{
        vec P=A[0],Q=A[1],R=A[2];
        int fl=0;
        for(auto t:B){
            if(in_circumcircle(P,Q,R,t)==0){
                fl=1;break;
            }
        }
        for(auto t:A){
            if(in_circumcircle(P,Q,R,t)!=2){
                fl=1;break;
            }
        }
        if(fl)cout<<"not a penguin";
        else cout<<"probably";
    }
    return 0;
}