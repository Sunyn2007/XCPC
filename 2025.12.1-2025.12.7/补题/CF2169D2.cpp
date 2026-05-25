#include <bits/stdc++.h>
using namespace std;
const long long N = 1e12, S = 1e6;
int t;
long long x, y, k;
void solve() {
    cin >> x >> y >> k;
    if (y == 1) {
        cout << -1 << '\n';
        return ;
    }
    long long cnt = 0;
    bool ok = true;
    while (cnt < x) {
        long long det = (k - 1) / (y - 1);
        if (det == 0 || k > N) break;
        if (det <= S) {
            long long tmp = (det + 1) * (y - 1) - (k - 1), cntt = (tmp % det == 0) ? (tmp / det) : (tmp / det + 1);
            if (cnt + cntt > x) {
                k += (x - cnt) * det;
                break;
            }
            cnt += cntt;
            k += cntt * det;
        }
        else k += det, cnt += 1;
    }
    if (k > N) cout << -1 << '\n';
    else cout << k << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}