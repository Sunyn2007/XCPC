#include <bits/stdc++.h>
using namespace std;
int t, n, res;
void mkq(int tp, long long x) {
    if (tp == 1) cout << 'I' << ' ' << x << '\n';
    if (tp == 2) cout << 'Q' << ' ' << x << '\n';
    cout.flush();
    cin >> res;
    return ;
}
void solve() {
    cin >> n;
    cout << 0 << '\n', cout.flush();
    mkq(1, 0);
    if (res == 1) { // k = 1 {0}
        int now = 1;
        long long ans = 0;
        for (int i = n; i >= 1; i--) {
            mkq(1, 1ll << i - 1);
            if (res > now) now = res, ans += (1ll << i - 1);
        }
        cout << 'A' << ' ' << 1 << ' ' << ans << '\n';
        cout.flush();
    }
    else { // k = 2 or k = 3 {0, c}
        long long ans = 0;
        for (int i = n; i >= 1; i--) {
            mkq(2, ans + (1ll << i - 1));
            if (res) ans += (1ll << i - 1);
        }
        if (ans == (1ll << n) - 1) {
            mkq(1, 1);
            if (res == 2) cout << 'A' << ' ' << 2 << ' ' << ans << '\n';
            else cout << 'A' << ' ' << 3 << ' ' << ans << '\n';
            cout.flush();
        }
        else {
            mkq(1, (1ll << n) - 1);
            mkq(2, (1ll << n) - 1);
            if (res == 1) cout << 'A' << ' ' << 2 << ' ' << ans << '\n';
            else cout << 'A' << ' ' << 3 << ' ' << ans << '\n';
        }
    }
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}