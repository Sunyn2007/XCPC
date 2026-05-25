#include <bits/stdc++.h>
using namespace std;
int t, n;
long long res, ans;
void mkq(int l, int r) {
    cout << '?' << ' ' << l << ' ' << r << '\n';
    cout.flush();
    cin >> res;
    return ;
}
void div(int sl, int sr, long long sum) {
    int len = sr - sl + 1;
    if (len == 1) {
        ans = max(ans, sum);
        return ;
    }
    if (len == 2) {
        ans = max(ans, sum >> 1);
        return ;
    }
    int l = sl, r = sr, mid, rs;
    while (l <= r) {
        mid = (l + r) >> 1;
        mkq(sl, mid);
        if (res == sum - res) {
            rs = mid;
            break;
        }
        else if (res > sum - res) r = mid - 1;
        else l = mid + 1;
    }
    if (rs - sl + 1 <= sr - rs)
        div(sl, rs, sum >> 1);
    else
        div(rs + 1, sr, sum >> 1);
    return ;
}
void solve() {
    cin >> n;
    ans = 1;
    mkq(1, n);
    div(1, n, res);
    cout << '!' << ' ' << ans << '\n';
    cout.flush();
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}