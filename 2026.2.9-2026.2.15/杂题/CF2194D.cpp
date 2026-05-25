#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int t, n, m, a[N], s[N];
int hsh(int x, int y) {
    return x * (m + 1) + y + 1;
}
int sum(int x1, int y1, int x2, int y2) {
    if (y1 > y2 || x1 > x2) return 0;
    return s[hsh(x2, y2)] - s[hsh(x2, y1 - 1)] - s[hsh(x1 - 1, y2)] + s[hsh(x1 - 1, y1 - 1)];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[hsh(i, j)];
            s[hsh(i, j)] = s[hsh(i, j - 1)] + s[hsh(i - 1, j)] - s[hsh(i - 1, j - 1)] + a[hsh(i, j)];
        }
    int y = m, x = 1, now = 0, tot = sum(1, 1, n, m);
    while (sum(1, y, n, m) < tot / 2) y -= 1;
    now = sum(1, y + 1, n, m);
    while (x <= n && now + a[hsh(x, y)] <= tot / 2) now += a[(hsh(x, y))], x += 1;
    string pth;
    pth.append(y - 1, 'R');
    pth.append(x - 1, 'D');
    pth.append(1, 'R');
    pth.append(n - x + 1, 'D');
    pth.append(m - y, 'R');
    cout << 1ll * now * (tot - now) << '\n' << pth << '\n';
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            a[hsh(i, j)] = s[hsh(i, j)] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}