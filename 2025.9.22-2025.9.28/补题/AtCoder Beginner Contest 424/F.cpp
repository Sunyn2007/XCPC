#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, INF = 0x7fffffff;
int n, q;
struct data1 {
    int minn, maxn;  
};
struct sgt {
    data1 d[(N << 2) + 5];
    data1 pushup(data1 a, data1 b) {
        data1 res;
        res.minn = min(a.minn, b.minn);
        res.maxn = max(a.maxn, b.maxn);
        return res;
    }
    void build(int k, int l, int r) {
        if (l == r) {
            d[k].minn = d[k].maxn = l;
            return ;
        }
        int m = (l + r) >> 1;
        build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
        d[k] = pushup(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    void update(int k, int l, int r, int p, int x) {
        if (l == r) {
            d[k].maxn = max(d[k].maxn, x);
            d[k].minn = min(d[k].minn, x);
            return ;
        }
        int m = (l + r) >> 1;
        if (m >= p) update(k << 1, l, m, p, x);
        else update(k << 1 | 1, m + 1, r, p, x);
        d[k] = pushup(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    data1 query(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) return d[k];
        int m = (l + r) >> 1;
        data1 res = {INF, 0};
        if (m >= s) res = pushup(res, query(k << 1, l, m, s, t));
        if (m < t) res = pushup(res, query(k << 1 | 1, m + 1, r, s, t));
        return res;
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    tr.build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        data1 res = tr.query(1, 1, n, a, b);
        if (res.minn < a || res.maxn > b) cout << "No" << '\n';
        else {
            cout << "Yes" << '\n';
            tr.update(1, 1, n, a, b);
            tr.update(1, 1, n, b, a);
        }
    }
    return 0;
}