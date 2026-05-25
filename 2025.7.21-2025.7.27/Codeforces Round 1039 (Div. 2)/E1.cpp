#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
struct sunyn {
    int num, val;
};
struct sgt{
    sunyn d[(N << 2) + 5];
    void build(int k, int l, int r) {
        if (l == r) {
            d[k].val = 0;
            d[k].num = l;
            return ;
        }
        int mid = (l + r) >> 1;
        build(k << 1, l, mid), build(k << 1 | 1, mid + 1, r);
        d[k].val = d[k << 1].val + d[k << 1 | 1].val;
        return ;
    }
    void upd(int k, int l, int r, int p, int x) {
        if (l == r) {
            d[k].val += x;
            return ;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) upd(k << 1, l, mid, p, x);
        else upd(k << 1 | 1, mid + 1, r, p, x);
        d[k].val = d[k << 1].val + d[k << 1 | 1].val;
        return ;
    }
    int sol(int k, int l, int r, int tmp) {
        if (l == r) return d[k].num;
        int mid = (l + r) >> 1, lv = d[k << 1].val;
        if (tmp <= lv) return sol(k << 1, l, mid, tmp);
        else return sol(k << 1 | 1, mid + 1, r, tmp - lv);
    }
}tr;
int t, n, k, a[N + 5];
void solve() {
    int ans = 0, resl, resr;
    cin >> n >> k;
    tr.build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tr.upd(1, 1, n, a[i], 1);
        if (i >= k) {
            if (k % 2 == 0) {
                int res = tr.sol(1, 1, n, k << 1 | 1);
                if (res > ans) 
                    ans = res, resl = i - k + 1, resr = i;
            }
            else {
                int res = tr.sol(1 ,1 , n, k << 1 | 1);
                if (res > ans)
                    ans = res, resl = i - k + 1, resr = i;
            }
            tr.upd(1, 1, n, a[i - k + 1], -1);
        }
    }
    cout << ans << ' ' << resl << ' ' << resr << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}