#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, Q = 1e5;
const long long INF1 = 2e14, INF2 = 0x7fffffffffffffff;
int n, m, q, s[N + 5], sn, blk[N + 5], id[N + 5];
long long d[N + 5], book[N + 5], tmp[N + 5], sum, tsum, ans[Q + 5];
struct qry {
    int l, r, id;
}qt[Q + 5];
bool cmp(qry a, qry b) {
    if (blk[a.l] == blk[b.l]) return a.r < b.r;
    return blk[a.l] < blk[b.l];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n - m + 1; i++) {
        cin >> s[i];
        if (i > 1) d[i + m - 1] = s[i - 1] - s[i] + d[i - 1];
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> qt[i].l >> qt[i].r, qt[i].id = i;
    sn = sqrt(1.0 * n);
    for (int i = 1; i <= n; i++)
        blk[i] = (i - 1) / sn + 1, id[i] = (i - 1) % m + 1;
    sort(qt + 1, qt + q + 1, cmp);
    int now = 0, p, tp;
    for (int i = 1; i <= q; i++) {
        if (qt[i].r - qt[i].l + 1 < m) {
            ans[qt[i].id] = INF2;
            continue;
        }
        if (blk[qt[i].l] != now) {
            now = blk[qt[i].l], p = now * sn + 1;
            sum = 1ll * m * INF1;
            for (int i = 1; i <= m; i++)
                book[i] = tmp[i] = INF1;
        }
        if (blk[qt[i].l] == blk[qt[i].r]) {
            tsum = 1ll * m * INF1;
            for (int j = qt[i].l; j <= qt[i].r; j++) {
                tsum -= tmp[id[j]];
                tmp[id[j]] = min(tmp[id[j]], d[j]);
                tsum += tmp[id[j]];
            }
            if (tsum >= s[1]) ans[qt[i].id] = -((tsum - s[1]) / m);
            else ans[qt[i].id] = (s[1] - tsum - 1) / m + 1;
            for (int j = qt[i].l; j <= qt[i].r; j++) tmp[id[j]] = INF1;
        }
        else {
            while (p <= qt[i].r) {
                sum -= book[id[p]];
                book[id[p]] = min(book[id[p]], d[p]);
                sum += book[id[p]];
                p += 1;
            }
            tsum = sum, tp = now * sn;
            while (tp >= qt[i].l) {
                if (tmp[id[tp]] == INF1) tmp[id[tp]] = book[id[tp]];
                tsum -= tmp[id[tp]];
                tmp[id[tp]] = min(tmp[id[tp]], d[tp]);
                tsum += tmp[id[tp]];
                tp -= 1;
            }
            if (tsum >= s[1]) ans[qt[i].id] = -((tsum - s[1]) / m);
            else ans[qt[i].id] = (s[1] - tsum - 1) / m + 1;
            while (tp <= now * sn) tmp[id[tp]] = INF1, tp += 1;
        }
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i] == INF2) cout << "unbounded\n";
        else cout << ans[i] << '\n';
    }
    return 0;
}