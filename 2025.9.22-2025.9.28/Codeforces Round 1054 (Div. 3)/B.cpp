#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = -1;
    for (int i = 2; i <= n; i += 2) 
        ans = max(ans, a[i] - a[i - 1]);
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}