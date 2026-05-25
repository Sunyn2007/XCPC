#include <bits/stdc++.h>
using namespace std;
int t, n, k, cnt[20], tot;
long long book[20], ans;
void pre() {
    book[0] = 1;
    for (int i = 1; i <= 19; i++) 
        book[i] = book[i - 1] * 3;
    return ;
}
void syn() {
    ans = 0, tot = 0;
    memset(cnt, 0, sizeof(cnt));
    return ;
}
void solve() {
    syn();
    cin >> n >> k;
    for (int i = 18; i >= 0; i--) {
        while (n >= book[i]) {
            n -= book[i];
            cnt[i] += 1;
            tot += 1;
            ans += book[i + 1] + i * book[i - 1];
        }
    }
    if (k < tot) cout << -1 << '\n';
    else {
        k -= tot;
        for (int i = 18; i >= 1; i--) {
            int tmp = k / 2;
            if (tmp > cnt[i]) {
                k -= cnt[i] * 2;
                ans -= cnt[i] * book[i - 1];
                cnt[i - 1] += cnt[i] * 3;
            }
            else {
                ans -= tmp * book[i - 1];
                break;
            }
        }
        cout << ans << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    while (t--) solve();
    return 0;
}