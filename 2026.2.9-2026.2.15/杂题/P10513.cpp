#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
struct sunyn {
    int len, l, r;
    int tlen, tl, tr;
};
int n, m;
string s;
struct sgt {
    sunyn d[(N << 2) + 5];
    bool tag[(N << 2) + 5];
    sunyn merge(sunyn x, sunyn y) {
        sunyn res;
        res.len = x.len + y.len + min(x.l, y.r);
        res.l = y.l + x.l - min(x.l, y.r);
        res.r = x.r + y.r - min(x.l, y.r);
        res.tlen = x.tlen + y.tlen + min(x.tl, y.tr);
        res.tl = y.tl + x.tl - min(x.tl, y.tr);
        res.tr = x.tr + y.tr - min(x.tl, y.tr);
        return res;
    }
    void pushdown(int k) {
        if (tag[k]) {
            swap(d[k << 1].len, d[k << 1].tlen), swap(d[k << 1].l, d[k << 1].tl), swap(d[k << 1].r, d[k << 1].tr);
            swap(d[k << 1 | 1].len, d[k << 1 | 1].tlen), swap(d[k << 1 | 1].l, d[k << 1 | 1].tl), swap(d[k << 1 | 1].r, d[k << 1 | 1].tr);
            tag[k << 1] = !tag[k << 1], tag[k << 1 | 1] = !tag[k << 1 | 1];
            tag[k] = false;
        }
        return ;
    }
    void build(int k, int l, int r) {
        tag[k] = false;
        if (l == r) {
            d[k].len = d[k].l = d[k].r = d[k].tlen = d[k].tl = d[k].tr = 0;
            if (s[l] == '(') d[k].l = 1, d[k].tr = 1;
            if (s[l] == ')') d[k].r = 1, d[k].tl = 1;
            return ;
        }
        int m = (l + r) >> 1;
        build(k << 1, l, m);
        build(k << 1 | 1, m + 1, r);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    void update(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) {
            swap(d[k].len, d[k].tlen), swap(d[k].l, d[k].tl), swap(d[k].r, d[k].tr);
            tag[k] = !tag[k];
            return ;
        }
        pushdown(k);
        int m = (l + r) >> 1;
        if (m >= s) update(k << 1, l, m, s, t);
        if (m < t) update(k << 1 | 1, m + 1, r, s, t);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    sunyn query(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) return d[k];
        pushdown(k);
        int m = (l + r) >> 1;
        if (m >= s && m < t) return merge(query(k << 1, l, m, s, t), query(k << 1 | 1 , m + 1, r, s, t));
        else if (m >= s) return query(k << 1, l, m, s, t);
        else return query(k << 1 | 1, m + 1, r, s, t);
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s, s = ' ' + s;
    tr.build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) tr.update(1, 1, n, l, r);
        if (op == 2) cout << tr.query(1, 1, n, l, r).len << '\n';
    }
    return 0;
}
/*
())()(
)(()()
*/