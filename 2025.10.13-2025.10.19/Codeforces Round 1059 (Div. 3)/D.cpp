#include <bits/stdc++.h>
using namespace std;
int t, n;
int mkq(int op, int l, int r) {
    int res;
    cout << op << ' ' << l << ' ' << r << '\n';
    cout.flush();
    cin >> res;
    return res;
}
void solve() {
    cin >> n;
    int len = mkq(2, 1, n) - mkq(1, 1, n);
    int l = 1, r = n, res;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (mkq(2, 1, mid) == mkq(1, 1, mid)) 
            l = mid + 1;
        else res = mid, r = mid - 1;
    }
    cout << '!' << ' ' << res << ' ' << res + len - 1 << '\n';
    cout.flush();
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}