#include <bits/stdc++.h>
#define int long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
const int N=5e5+5;
int n,a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int tmp=1500;
    fu(i,1,n){
        int x;cin>>x;
        tmp+=x;
        if(tmp>=4000){
            cout<<i;return 0;
        }
    }
    cout<<-1;
    return 0;
}