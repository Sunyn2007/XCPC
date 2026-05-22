#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;
void solve() {
    cin >> n >> a >> b;
    if (3 * a < b) cout << 1ll * n * a << '\n';
    else {
        long long ans = 0;
        ans += 1ll * n / 3 * b;
        n %= 3;
        if (n * a < b) ans += n * a;
        else ans += b;
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