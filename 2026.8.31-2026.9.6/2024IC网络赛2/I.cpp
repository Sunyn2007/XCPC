#include <bits/stdc++.h>
using namespace std;
int t, n, ans[33];
void solve() {
    cin >> n;
    if (n == 0) {
        cout << "NO" << '\n';
        return ;
    } 
    n -= 1;
    if ((n & 1) && ((n >> 1) & 1)) cout << "NO" << '\n';
    else {
        for (int i = 1; i <= 31; i++) ans[i] = -1;
        ans[32] = 1;
        cout << "YES" << '\n';
        int now;
        if (!(n & 1)) n >>= 1, now = 1;
        else ans[1] = 0, n >>= 2, now = 2;
        while (n) {
            if (n & 1) ans[now] = 1;
            n >>= 1, now += 1;
        }
        for (int i = 1; i <= 4; i++) {
            for (int j = (i - 1) * 8 + 1; j <= i * 8; j++)
                cout << ans[j] << ' ';
            cout << '\n';
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}