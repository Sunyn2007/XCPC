#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], book[N + 5];
void solve() {
    long long res1 = 0, res2 = 0;
    int num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1, j; i <= n; i = j + 1) {
        j = i;
        while (a[j + 1] == a[i]) j += 1;
        int cnt = j - i + 1;
        res1 += 1ll * a[i] / 2 * cnt, res2 += 1ll * a[i] / 2 * cnt;
        if (a[i] % 2 == 1) book[++num] = cnt;
    }
    sort(book + 1, book + num + 1);
    bool now = false;
    for (int i = num; i >= 1; i--) {
        if (!now) res1 += book[i];
        else res2 += book[i];
        now = !now;
    }
    cout << res1 << ' ' << res2 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}