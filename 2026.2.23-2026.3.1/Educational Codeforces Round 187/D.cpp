#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, M = 1e6;
int t, n, m, len, a[N + 5], b[M + 5], book[N + M + 5];
int gcd(int x, int y) {
    if (x % y == 0) return y;
    return (y, x % y);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1), len = unique(a + 1, a + n + 1) - (a + 1);
    for (int i = 1; i <= len; i++)
        for (int j = a[i]; j <= n + m; j += a[i])
            book[j] += 1;
    int cnta = 0, cntb = 0, cntab = 0;
    for (int i = 1; i <= m; i++) {
        if (book[b[i]] == 0) cntb += 1;
        else if (book[b[i]] < len) cntab += 1;
        else cnta += 1;
    }
    cnta += (cntab + 1) / 2, cntb += cntab / 2;
    if (cnta > cntb) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
    for (int i = 1; i <= n + m; i++) book[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}