#include <bits/stdc++.h>
using namespace std;
const long long N = 1e12, SYN = 5e7;
int t;
long long x, y, k;
long long calc(long long num) {
    if (num / y <= SYN) {
        long long cnt = 0;
        while (cnt < x) {
            if (num < y) break;
            long long det = num / y, tmp = num % y, cntt = tmp / det + 1;
            if (cnt + cntt > x) {
                num -= (x - cnt) * det;
                break;
            }
            cnt += cntt;
            num -= cntt * det;
        }
    }
    else {
        long long cnt = 0;
        while (num > y && cnt < x) {
            num -= num / y;
            cnt += 1;
        }
    }
    return num;
}
void solve() {
    cin >> x >> y >> k;
    long long l = 1, r = N, res = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (calc(mid) >= k) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    if (!res) cout << -1 << '\n';
    else cout << res << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}