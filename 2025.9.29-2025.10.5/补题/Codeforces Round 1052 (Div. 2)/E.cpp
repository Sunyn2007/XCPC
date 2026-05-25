#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, a[N + 5];
struct sgt {
    int d[(N << 2) + 5], tag[(N << 2) + 5];
    void build(int k, int l, int r) {
        d[k] = tag[k] = 0;
        if (l == r) return ;
        int m = (l + r) >> 1;
        build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
        return ;
    }
    void pushdown(int k) {
        if (tag[k]) {
            d[k << 1] += tag[k], d[k << 1 | 1] += tag[k];
            tag[k << 1] += tag[k], tag[k << 1 | 1] += tag[k];
            tag[k] = 0;
        }
        return ;
    }
    void upd1(int k, int l, int r, int p) {
        if (l == r) {
            d[k] = 0;
            return ;
        }
        pushdown(k);
        int m = (l + r) >> 1;
        if (m >= p) upd1(k << 1, l, m, p);
        else upd1(k << 1 | 1, m + 1, r, p);
        d[k] = max(d[k << 1], d[k << 1 | 1]);
        return ;
    }
    void upd2(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) {
            d[k] += 1, tag[k] += 1;
            return ;
        }
        pushdown(k);
        int m = (l + r) >> 1;
        if (m >= s) upd2(k << 1, l, m, s, t);
        if (m < t) upd2(k << 1 | 1, m + 1, r, s, t);
        d[k] = max(d[k << 1], d[k << 1 | 1]);
        return ;
    }
}tr;
void solve() {
    cin >> n;
    tr.build(1, 0, n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 1) tr.upd2(1, 0, n, 0, a[i] - 1);
        tr.upd1(1, 0, n, a[i]);
        cout << tr.d[1] << ' ';
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}