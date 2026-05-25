#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, a[N + 5], res[N + 5], l[N + 5], r[N + 5];
int syn(int x) {
    return x < 0 ? -x : x;
}
bool check() {
    l[1] = r[n] = 0;
    for (int i = 2; i <= n; i++) {
        if (res[i - 1] == 0) l[i] = l[i - 1] + 1;
        else l[i] = l[i - 1];
    }
    for (int i = n - 1; i >= 1; i--) {
        if (res[i + 1] == 1) r[i] = r[i + 1] + 1;
        else r[i] = r[i + 1];
    }
    for (int i = 1; i <= n; i++)
        if (l[i] + r[i] + 1 != a[i]) return false;
    return true;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 2; i <= n; i++) if (syn(a[i] - a[i - 1]) >= 2) flag = false;
    if (!flag) cout << 0 << '\n';
    else {
        int ans = 0;
        res[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) res[i] = res[i - 1] ^ 1;
            else res[i] = res[i - 1];
        }
        if (check()) ans += 1;
        res[1] = 1;for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) res[i] = res[i - 1] ^ 1;
            else res[i] = res[i - 1];
        }
        if (check()) ans += 1;
        cout << ans << '\n';
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