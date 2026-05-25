#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int gb(int x, int y) {
    return (x >> y - 1) & 1;
}
int syn(int x) {
    return x < 0 ? -x : x;
}
void upd(int &p, int &q, int tp, int tq) {
    if (syn(tp - x) + syn(tq - y) < syn(p - x) + syn(q - y))
        p = tp, q = tq;
    return ;
}
void solve() {
    cin >> x >> y;
    int p = 0, q = 0;
    if ((x & y) == 0) p = x, q = y;
    for (int i = 30; i >= 1; i--) {
        int bx = gb(x, i), by = gb(y, i);
        if (bx == 1 && by == 1) {
            int tp, tq;
            tp = (x >> i - 1 << i - 1) + (1 << i - 1), tq = y;
            if ((tp & tq) == 0) upd(p, q, tp, tq);
            tp = x, tq = (y >> i - 1 << i - 1) + (1 << i - 1);
            if ((tp & tq) == 0) upd(p, q, tp, tq);
            tp = (x >> i - 1 << i - 1), tq = (y >> i - 1 << i - 1) - 1;
            upd(p, q, tp, tq);
            break;
        }
    }
    cout << p << ' ' << q << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}