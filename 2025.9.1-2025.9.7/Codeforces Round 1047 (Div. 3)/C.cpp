#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b;
void solve() {
    cin >> a >> b;
    if (b % 2 == 1) {
        if (a % 2 == 1) 
            cout << a * b + 1 << '\n';
        else cout << -1 << '\n';
    }
    else {
        if (a % 2 == 1) {
            a <<= 1, b >>= 1;
            if ((a + b) % 2 != 0) cout << -1 << '\n';
            else {
                if (b % 2 == 1) cout << a + b << '\n';
                else cout << max(a + b, a * (b / 2) + 2) << '\n';
            }
        }
        else cout << max(a + b, a * (b / 2) + 2) << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
1 1 
0 1
1 0
0 0
*/