#include <bits/stdc++.h>
using namespace std;
const int N = 3e3;
int t, n, h[N * 2 + 5], pre[N * 2 + 5], suf[N * 2 + 5];
long long ans[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i], h[i + n] = h[i];
    for (int i = 1; i <= n; i++) {
        pre[i] = 0, suf[i + n] = 0;
        for (int j = i + 1; j < i + n; j++)
            pre[j] = max(pre[j - 1], h[j - 1]);
        for (int j = i + n - 1; j > i; j--)
            suf[j] = max(suf[j + 1], h[j]);
        long long res = 0;
        for (int j = i + 1; j < i + n; j++)
            res += min(pre[j], suf[j]);
        ans[i] = res;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}