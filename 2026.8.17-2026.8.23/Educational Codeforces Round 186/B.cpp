#include <bits/stdc++.h>
using namespace std;
int t, a, b;
void solve() {
    cin >> a >> b;
    int res1 = 0, res2 = 0, ta, tb;
    bool now;
    ta = a, tb = b, now = false;
    while (true) {
        if (!now) {
            if (ta >= (1 << res1)) ta -= (1 << res1), res1 += 1;
            else break;
        }
        else {
            if (tb >= (1 << res1)) tb -= (1 << res1), res1 += 1;
            else break;
        }
        now = !now;
    }
    ta = a, tb = b, now = true;
    while (true) {
        if (!now) {
            if (ta >= (1 << res2)) ta -= (1 << res2), res2 += 1;
            else break;
        }
        else {
            if (tb >= (1 << res2)) tb -= (1 << res2), res2 += 1;
            else break;
        }
        now = !now;
    }
    cout << max(res1, res2) << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}