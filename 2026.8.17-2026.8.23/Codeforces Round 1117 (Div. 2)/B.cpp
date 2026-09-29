#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[105], b[105];
void solve() {
    cin >> n >> m;
    long long tmp1 = 0, tmp2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) {
            if (a[i - 1] >= a[i]) tmp1 += a[i - 1] - a[i] + 1;
            else tmp1 += 1;
        }
    }
    tmp1 += a[n];
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (i > 1) {
            if (b[i - 1] >= b[i]) tmp2 += b[i - 1] - b[i] + 1;
            else tmp2 += 1;
        }
    }
    tmp2 += b[m];
    if (tmp1 >= tmp2) cout << 1 << '\n';
    else cout << 2 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}