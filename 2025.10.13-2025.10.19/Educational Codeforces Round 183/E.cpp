#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int ac, dr, n, m, a[N + 5], d[N + 5], cnt[N + 5], s[N + 5];
struct syn {
    int sum, minn;
};
struct sgt {
    syn d[(N << 2) + 5];
    int tag[(N << 2) + 5];
    syn merge(syn x, syn y) {
        syn res;
        res.sum = x.sum + y.sum;
        res.minn = min(x.minn, y.minn);
        return res;
    }
    void pushdown(int k) {
        if (tag[k]) {
            d[k << 1].sum += tag[k], d[k << 1 | 1].sum += tag[k];
            d[k << 1].minn += tag[k], d[k << 1 | 1].minn += tag[k];
            tag[k << 1] += tag[k], tag[k << 1 | 1] += tag[k];
            tag[k] = 0;
        }
        return ;
    }
    void build(int k, int l, int r) {
        if (l == r) {
            d[k].sum = d[k].minn = s[l];
            return ;
        }
        int m = (l + r) >> 1;
        build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    void upd(int k, int l, int r, int s, int t, int x) {
        if (l >= s && r <= t) {
            d[k].sum += x, d[k].minn += x;
            tag[k] += x;
            return ;
        }
        pushdown(k);
        int m = (l + r) >> 1;
        if (m >= s) upd(k << 1, l, m, s, t, x);
        if (m < t) upd(k << 1 | 1, m + 1, r, s, t, x);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    int query(int k, int l, int r) {
        if (l == r) return l;
        pushdown(k);
        int m = (l + r) >> 1;
        if (d[k << 1].minn < 0) return query(k << 1, l, m);
        else return query(k << 1 | 1, m + 1, r);
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> ac >> dr >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        int v = max(a[i] - ac, 0) + max(d[i] - dr, 0);
        if (v <= n) cnt[v] += 1;
    }
    s[0] = cnt[0] - 1;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + cnt[i] - 1;
    tr.build(1, 0, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int num, aa, dd, v1, v2;
        cin >> num >> aa >> dd;
        v1 = max(a[num] - ac, 0) + max(d[num] - dr, 0);
        v2 = max(aa - ac, 0) + max(dd - dr, 0);
        a[num] = aa, d[num] = dd;
        if (v1 <= n) tr.upd(1, 0, n, v1, n, -1);
        if (v2 <= n) tr.upd(1, 0, n, v2, n, 1);
        cout << tr.query(1, 0, n) << '\n';
    }
    return 0;
}