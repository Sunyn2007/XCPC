#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int t, n, k;
void solve() {
    cin >> n >> k;
    int now = 0, ans = 0;
    while (n) {
        int tmp = (1 << now);
        if (n >= 1ll * k * tmp) 
            ans += k, n -= k * tmp;
        else ans += n / tmp, n = 0;
        now += 1;
    }
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