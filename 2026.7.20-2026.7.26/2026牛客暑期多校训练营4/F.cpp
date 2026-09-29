#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long a[N + 5], b[N + 5], p[N + 5];
int n, t, q, f[N + 5][61], g[N + 5][61], sl[N + 5], sr[N + 5]; 
struct sgt {
    int d[(N << 2) + 5];
    void build(int k, int l, int r) {
        d[k] = n + 1;
        if (l == r) return ;
        int m = (l + r) >> 1;
        build(k << 1, l, m);
        build(k << 1 | 1, m + 1, r);
        return ;
    }
    void upd(int k, int l, int r, int p, int x) {
        if (l == r) {
            d[k] = x;
            return ;
        }
        int m = (l + r) >> 1;
        if (m >= p) upd(k << 1, l, m, p, x);
        else upd(k << 1 | 1, m + 1, r, p, x);
        d[k] = min(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    int query(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) return d[k];
        int m = (l + r) >> 1, res = n + 1;
        if (m >= s) res = min(res, query(k << 1, l, m, s, t));
        if (m < t) res = min(res, query(k << 1 | 1, m + 1, r, s, t));
        return res;
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    t = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = lower_bound(b + 1, b + t + 1, a[i]) - b;
        sl[i] = lower_bound(b + 1, b + t + 1, 2 * a[i]) - b;
        sr[i] = lower_bound(b + 1, b + t + 1, 3 * a[i]) - b;
    }
    for (int i = 1; i <= n; i++) f[i][1] = i;
    for (int k = 2; k <= 60; k++) {
        tr.build(1, 1, t);
        for (int i = n; i >= 1; i--) {
            int l = sl[i], r = sr[i];
            if (l == t + 1 || (r == 1 && b[1] > 3 * a[i])) f[i][k] = n + 1;
            else {
                if (r == t + 1 || b[r] > 3 * a[i]) r -= 1;
                if (l <= r) f[i][k] = tr.query(1, 1, t, l, r);
                else f[i][k] = n + 1;
            }
            tr.upd(1, 1, t, p[i], f[i][k - 1]);
        }
        g[n + 1][k] = n + 1;
        for (int i = n; i >= 1; i--)
            g[i][k] = min(g[i + 1][k], f[i][k]);
    }
    for (int i = 1; i <= q; i++) {
        int l, r, ans = 0;
        cin >> l >> r;
        for (int k = 1; k <= 60; k++) {
            if (g[l][k] <= r) ans = k;
            else break;
        }
        cout << ans << '\n';
    }
    return 0;
}