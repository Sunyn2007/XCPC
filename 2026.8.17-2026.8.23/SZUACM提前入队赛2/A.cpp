#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, a[N + 5], bk[2 * N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], bk[a[i]] = i;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * a[i] <= 2 * n - 1; j++)
            if (bk[j] && bk[j] < i && bk[j] + i == j * a[i]) ans += 1;
    cout << ans << '\n';
    for (int i = 1; i <= 2 * n; i++) bk[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}