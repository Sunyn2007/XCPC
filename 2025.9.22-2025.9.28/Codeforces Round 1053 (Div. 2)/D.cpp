#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, MOD = 998244353;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] < 2 || a[n] > 0) cout << 0 << '\n';
    else {
        a[1] -= 2;
        long long ans = 1;
        int now = n - 2, mid = (n % 2 == 0 ? n / 2 : n / 2 + 1);
        for (int i = n - 1; i >= 1; i--)
            if (a[i]) {
                int res = 0;
                if (i > mid) {
                    if (a[i] > 1) res = 0;
                    else res = now, now -= 2;
                }
                else {
                    if (a[i] > ) res = 0;
                    else res = 
                }
            }
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