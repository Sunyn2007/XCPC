#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 2e5, Q = 1e5;
int t, n, m, q, a[N + 5], b[N + 5], tot[N + M + 5][2];
long long sa[N + 5], sb[M + 5], sum[N + M + 5];
bool cmp(int a, int b) {
    return a > b;
}
void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1, cmp), sort(b + 1, b + m + 1, cmp);
    for (int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= m; i++) sb[i] = sb[i - 1] + b[i];
    int pa = 1, pb = 1, now = 1;
    while (now <= n + m) {
        tot[now][0] = tot[now - 1][0], tot[now][1] = tot[now - 1][1];
        if (pb > m || a[pa] >= b[pb]) 
            tot[now][0] += 1, sum[now] = sum[now - 1] + a[pa], pa += 1;
        else tot[now][1] += 1, sum[now] = sum[now - 1] + b[pb], pb += 1;
        now += 1;
    }
    for (int i = 1; i <= q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        int cnta = tot[z][0], cntb = tot[z][1];
        if (cnta > x) cout << sa[x] + sb[z - x] << "\n";
        else if(cntb > y) cout << sb[y] + sa[z - y] << "\n";
        else cout << sum[z] << '\n';
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