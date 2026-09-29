#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 1e5;
int t, n, m, x, y, a[N + M + 5], b[N + M + 5];
bool bk[N + M + 5], bk1[N + M + 5], bk2[N + M + 5];
void solve() {
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= x; i++) cin >> a[i], bk1[a[i]] = true;
    for (int i = 1; i <= y; i++) cin >> b[i], bk2[b[i]] = true;
    long long ans = 0;
    if (x >= n && y >= m) {
        int cnt = 0, cnt1 = 0, cnt2 = 0;
        for (int i = n + m; i >= 1; i--) {
            if (bk1[i] && bk2[i]) ans += i, cnt += 1;
            else if (bk1[i] && cnt1 < n) ans += i, cnt1 += 1;
            else if (bk2[i] && cnt2 < m) ans += i, cnt2 += 1;
            if (cnt + cnt1 + cnt2 == n + m - 1) break;
        }
    }
    else if (x >= n) {
        for (int i = 1; i <= y; i++)
            ans += b[i], bk[b[i]] = true;
        int cnt = 0;
        for (int i = x; i >= 1; i--)
            if (!bk[a[i]] && cnt < n)
                ans += a[i], cnt += 1;
    }
    else if (y >= m) {
        for (int i = 1; i <= x; i++)
            ans += a[i], bk[a[i]] = true;
        int cnt = 0;
        for (int i = y; i >= 1; i--)
            if (!bk[b[i]] && cnt < m)
                ans += b[i], cnt += 1;
    }
    else {
        for (int i = 1; i <= x; i++)
            ans += a[i], bk[a[i]] = true;
        for (int i = 1; i <= y; i++)
            if (!bk[b[i]]) ans += b[i];
    }
    cout << ans << '\n';
    for (int i = 1; i <= n + m; i++) bk[i] = bk1[i] = bk2[i] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}