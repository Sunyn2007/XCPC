#include <bits/stdc++.h>
using namespace std;
const int N = 8;
int t, n, a[N + 5], cnt[3];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) cnt[0] += 1;
        if (a[i] == 1) cnt[1] += 1;
        if (a[i] == -1) cnt[2] += 1;
    }
    if (cnt[2] % 2 == 1) cout << cnt[0] + 2 << '\n';
    else cout << cnt[0] << '\n';
    memset(cnt, 0, sizeof(cnt));
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}