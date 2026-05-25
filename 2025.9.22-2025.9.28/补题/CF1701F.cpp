#include <bits/stdc++.h>
using namespace std;
const int Q = 2e5, V = 2e5;
int q, d, a[Q + 5], book[V + 5];
long long ans;
struct data1 {
    int cnt;
    long long sum;
};
struct sgt {
    int tag[(V << 2) + 5];
    data1 d[(V << 2) + 5];
    data1 merge(data1 a, data1 b) {
        data1 res;
        res.cnt = a.cnt + b.cnt;
        res.sum = a.sum + b.sum;
        return res;
    }
    void pushdown(int k) {
        if (tag[k] != 0) {
            d[k << 1].sum += 1ll * tag[k] * d[k << 1].cnt;
            d[k << 1 | 1].sum += 1ll * tag[k] * d[k << 1 | 1].cnt;
            tag[k << 1] += tag[k], tag[k << 1 | 1] += tag[k];
            tag[k] = 0;
        }
        return ;
    }
    void build(int k, int l, int r) {
        tag[k] = 0;
        if (l == r) {
            d[k].cnt = d[k].sum = 0;
            return ;
        }
        int m = (l + r) >> 1;
        build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    void upd1(int k, int l, int r, int p, int x, int y) {
        if (l == r) {
            d[k].cnt += x;
            d[k].sum += y;
            return ;
        }
        pushdown(k);
        int m = (l + r) >> 1;
        if (m >= p) upd1(k << 1, l, m, p, x, y);
        else upd1(k << 1 | 1, m + 1, r, p, x, y);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    void upd2(int k, int l, int r, int s, int t, int x) {
        if (l >= s && r <= t) {
            d[k].sum += x * d[k].cnt;
            tag[k] += x;
            return ;
        }
        pushdown(k);
        int m = (l + r) >> 1;
        if (m >= s) upd2(k << 1, l, m, s, t, x);
        if (m < t) upd2(k << 1 | 1, m + 1, r, s, t, x);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    data1 query(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) return d[k];
        pushdown(k);
        int m = (l + r) >> 1;
        data1 res = {0, 0};
        if (m >= s) res = merge(res, query(k << 1, l, m, s, t));
        if (m < t) res = merge(res, query(k << 1 | 1, m + 1, r, s, t));
        return res;
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> q >> d;
    tr.build(1, 1, V);
    for (int i = 1; i <= q; i++) {
        cin >> a[i];
        if (!book[a[i]]) {
            int res;
            if (a[i] < V) {
                res = tr.query(1, 1, V, a[i] + 1, min(V, a[i] + d)).cnt;
                ans += 1ll * res * (res - 1) / 2;
            }
            if (a[i] > 1) ans += tr.query(1, 1, V, max(1, a[i] - d), a[i] - 1).sum;
            tr.upd1(1, 1, V, a[i], 1, res);
            if (a[i] > 1) tr.upd2(1, 1, V, max(1, a[i] - d), a[i] - 1, 1);
            book[a[i]] = true;
        }
        else {
            int res1;
            data1 res2;
            if (a[i] < V) {
                res1 = tr.query(1, 1, V, a[i] + 1, min(V, a[i] + d)).cnt;
                ans -= 1ll * res1 * (res1 - 1) / 2;
            }
            if (a[i] > 1) {
                res2 = tr.query(1, 1, V, max(1, a[i] - d), a[i] - 1);
                ans -= res2.sum - res2.cnt;
            }
            tr.upd1(1, 1, V, a[i], -1, -res1);
            if (a[i] > 1) tr.upd2(1, 1, V, max(1, a[i] - d), a[i] - 1, -1);
            book[a[i]] = false;
        }
        cout << ans << '\n';
    }
    return 0;
}