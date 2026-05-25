#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5], book[N + 5];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], book[a[i]] += 1;
    sort(a + 1, a + n + 1);
    int mex;
    if (a[1] > 0) mex = 0;
    else {
        int now = 2;
        while ((a[now] == a[now - 1] || a[now] == a[now - 1] + 1) && now <= n) now += 1;
        mex = a[now - 1] + 1;
    }
    if (mex > k) cout << book[k] << '\n';
    else if (mex == k) cout << 0 << '\n';
    else {
        int ans = 0;
        for (int i = mex; i <= k - 1; i++)
            if (!book[i]) {
                ans += 1;
                if (book[k]) book[k] -= 1;
            }
        ans += book[k];
        cout << ans << '\n';
    }
    for (int i = 1; i <= n; i++) book[a[i]] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}