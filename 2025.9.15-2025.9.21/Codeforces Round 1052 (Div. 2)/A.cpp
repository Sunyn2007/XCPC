#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5], book[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        book[a[i]] += 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j <= n; j++)
            if (book[j] >= i) res += i;
        ans = max(ans, res);
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) book[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}