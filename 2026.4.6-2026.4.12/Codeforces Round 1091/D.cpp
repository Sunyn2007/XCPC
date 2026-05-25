#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, K = 2e5;
int t, n, k, a[N + 5], p[K + 5];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> p[i];
    bool flag = false;
    int now = 1, l = 0, r = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (now <= n && a[i] == p[now]) {
            if (flag) ans += l, flag = l = r = 0;
            else if (l) flag = true;
            now += 1;
        }
        else if (i == 1 || a[i] != a[i - 1]) {
            if (flag) {
                r += 1;
                if (r == l) {
                    ans += l;
                    flag = l = r = 0;
                }
            }
            else l += 1;
        }
    }
    ans += l;
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
01010
10101
11011
11101
11111
*/