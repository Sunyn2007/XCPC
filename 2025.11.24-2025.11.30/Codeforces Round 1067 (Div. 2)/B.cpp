#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[(N << 1) + 5], book[(N << 1) + 5];
void solve() {
    int ans = 0, tot0 = 0, tot1 = 0, cnt0 = 0, cnt1 = 0;
    cin >> n;
    for (int i = 1; i <= n * 2; i++) 
        cin >> a[i], book[a[i]] += 1;
    for (int i = 1; i <= n * 2; i++)
        if (book[i]) {
            if (book[i] % 2 == 0) {
                tot0 += 1, tot1 += book[i] - 1;
                cnt0 += (book[i] - 2) / 2, ans += 2;
            }
            else tot1 += book[i], cnt1 += book[i], ans += 1;
            book[i] = 0;
        }
    if (cnt0 * 4 < tot1 - tot0) {
        tot1 -= cnt0 * 2, tot0 += cnt0 * 2;
        if (cnt1 * 2 < tot1 - tot0) {
            tot1 -= cnt1, tot0 += cnt1;
            ans -= tot1 - tot0;
        }
    }
    else if ((tot1 - tot0) % 4 != 0 && !cnt1) ans -= 2;
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