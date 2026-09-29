#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        int x,k;
        cin>>x>>k;
        int tmp=(1<<__builtin_ctz(x));
        if(k>=tmp){
            cout<<"Alice\n";
        }
        else cout<<"Bob\n";
    }
    return 0;
}