#include <bits/stdc++.h>
using namespace std;
const int N = 3e5, S = 5000;
int t, m, n, a[N + 5], c[S + 5][S + 5];
void init() {
    for (int i = 0; i <= S; i++) c[i][0] = 1;
    for (int i = 1; i <= S; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
    return ;
}
void solve() {
    int s = 0, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s += a[i];
    for (int i = 1; i <= n; i++) {
        ans = 1ll * ans * c[s][a[i]] % m;
        s -= a[i];
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t >> m;
    init();
    while (t--) solve();
    return 0;
}