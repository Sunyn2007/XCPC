#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int t, n, a[N + 5], bk[1005];
void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], bk[a[i]] += 1, ans += a[i];
    for (int i = 1; i <= n; i++)
        if (bk[a[i]] > n - bk[a[i]] + 2) {
            ans -= (bk[a[i]] - (n - bk[a[i]] + 2)) * a[i];
            break;
        }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) bk[a[i]] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}