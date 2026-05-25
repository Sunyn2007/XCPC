#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        if (i % 2 == 0) a[i] = maxn;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        if (i % 2 == 1) {
            if (i == 1) {
                if (a[i] >= a[i + 1]) ans += a[i] - a[i + 1] + 1;
            }
            else if (i == n) {
                if (a[i] >= a[i - 1]) ans += a[i] - a[i - 1] + 1;
            }
            else {
                int minn = min(a[i + 1], a[i - 1]);
                if (a[i] >= minn) ans += a[i] - minn + 1;
            }
        }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}