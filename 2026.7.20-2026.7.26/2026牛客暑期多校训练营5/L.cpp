#include <bits/stdc++.h>
using namespace std;
const int N = 5000, M = 5000;
int t, n, m;
long long a[N + 5][M + 5], f[N + 5][M + 5];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j];
    if (n == 1 || m == 1) {
        bool ok = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] != a[1][1]) ok = false;
        if (ok) cout << 0 << '\n';
        else cout << -1 << '\n';
    }
    else {
        bool ok = true;
        long long x = a[1][2] + a[2][1] - a[1][1];
        if (x < a[1][1]) ok = false;
        f[1][1] = x - a[1][1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (a[i][j] + f[i][j] != x) ok = false;
                if (i < n && j < m) {
                    if (a[i][j + 1] + f[i][j + 1] > x || a[i][j + 1] + f[i][j + 1] + f[i][j] < x) ok = false;
                    f[i][j] -= x - (a[i][j + 1] + f[i][j + 1]), f[i][j + 1] = x - a[i][j + 1];
                    f[i + 1][j] += f[i][j], f[i][j] = 0;
                }
                else if (i < n)
                    f[i + 1][j] += f[i][j], f[i][j] = 0;
                else if (j < m) 
                    f[i][j + 1] += f[i][j], f[i][j] = 0;
            }
        if (ok) cout << x - a[1][1] << '\n';
        else cout << -1 << '\n';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            f[i][j] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}