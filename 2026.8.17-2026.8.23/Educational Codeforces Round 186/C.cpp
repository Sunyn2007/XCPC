#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int t, n, a[2 * N + 5], b[2 * N + 5], c[2 * N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], b[i + n] = b[i];
    for (int i = 1; i <= n; i++) cin >> c[i], c[i + n] = c[i];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        bool fl = true;
        for (int j = i; j <= i + n - 1; j++)
            if (b[j] <= a[j - i + 1]) fl = false;
        if (fl) cnt1 += 1;
    }
    for (int i = 1; i <= n; i++) {
        bool fl = true;
        for (int j = i; j <= i + n - 1; j++)
            if (c[j] <= b[j - i + 1]) fl = false;
        if (fl) cnt2 += 1;
    }
    cout << 1ll * cnt1 * cnt2 * n << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}