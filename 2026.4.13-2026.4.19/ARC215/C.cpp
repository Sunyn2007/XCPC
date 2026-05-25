#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, x[N + 5], y[N + 5], z[N + 5];
struct BT {
    int v[N + 5];
    void init() {
        for (int i = 1; i <= n; i++) v[i] = 0;
        return ;
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int x, int y) {
        for (int i = x; i <= n; i += lowbit(i))
            v[i] = max(v[i], y);
        return ;   
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res = max(res, v[i]);
        return res;
    }
}xy, xz, yx, yz, zx, zy;
void solve() {
    cin >> n;
    xy.init(), xz.init(), yx.init(), yz.init(), zx.init(), zy.init();
    int mxx = 0, mxy = 0, mxz = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
        mxx = max(mxx, x[i]), mxy = max(mxy, y[i]), mxz = max(mxz, z[i]);
        xy.update(x[i], y[i]), xz.update(x[i], z[i]);
        yx.update(y[i], x[i]), yz.update(y[i], z[i]);
        zx.update(z[i], x[i]), zy.update(z[i], y[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        if (xy.query(x[i]) == mxy || zy.query(z[i]) == mxy) flag = true;
        if (xz.query(x[i]) == mxz || yz.query(y[i]) == mxz) flag = true;
        if (yx.query(y[i]) == mxx || zx.query(z[i]) == mxx) flag = true;
        if (flag) ans += 1;
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}