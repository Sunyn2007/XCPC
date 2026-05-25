#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 1e5, Q = 1e5;
int n, m, q;
long long ans[Q + 5];
vector<pair<int, int> > s[N + 5], t[N + 5];
struct qry {
    int k, l, r, id;
}qq[M + 5];
bool cmp(qry a, qry b) {
    return a.k < b.k;
}
struct syn {
    long long lv, rv, mv, sv;
};
struct sgt {
    syn d[(M << 2) + 5];
    syn merge(syn ls, syn rs) {
        syn res;
        res.lv = max(ls.lv, ls.sv + rs.lv);
        res.rv = max(rs.rv, rs.sv + ls.rv);
        res.mv = max({ls.mv, rs.mv, ls.rv + rs.lv});
        res.sv = ls.sv + rs.sv;
        return res;
    }
    void build(int k, int l, int r) {
        d[k].lv = d[k].rv = d[k].mv = d[k].sv = 0;
        if (l == r) return ;
        int m = (l + r) >> 1;
        build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
        return ; 
    } 
    void update(int k, int l, int r, int p, int x) {
        if (l == r) {
            d[k].lv = d[k].rv = d[k].mv = d[k].sv = x;
            return ;
        }
        int m = (l + r) >> 1;
        if (p <= m) update(k << 1, l, m, p, x);
        else update(k << 1 | 1, m + 1, r, p, x);
        d[k] = merge(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    syn query(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) return d[k];
        int m = (l + r) >> 1;
        if (m >= s && m < t) return merge(query(k << 1, l, m, s, t), query(k << 1 | 1, m + 1, r, s, t));
        else if (m >= s) return query(k << 1, l, m, s, t);
        else return query(k << 1 | 1, m + 1, r, s, t); 
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        s[l].push_back(make_pair(i, x));
        t[r].push_back(make_pair(i, 0));
    }
    cin >> q;
    for (int i = 1; i <= q; i++) 
        cin >> qq[i].k >> qq[i].l >> qq[i].r, qq[i].id = i;
    sort(qq + 1, qq + q + 1, cmp);
    tr.build(1, 1, m);
    int now = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < s[i].size(); j++)
            tr.update(1, 1, m, s[i][j].first, s[i][j].second);
        while (now <= q && qq[now].k == i) {
            syn res = tr.query(1, 1, m, qq[now].l, qq[now].r);
            ans[qq[now].id] = max({res.lv, res.rv, res.mv});
            now += 1;
        }
        for (int j = 0; j < t[i].size(); j++)
            tr.update(1, 1, m, t[i][j].first, t[i][j].second);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}