#include <bits/stdc++.h>
using namespace std;
int t, n;
int res;
void mkq1(int l, int r) {
    cout << '?' << ' ' << (r - l + 1) << ' ';
    for (int i = l; i <= r; i++) cout << i << ' ';
    cout << '\n';
    cout.flush();
    cin >> res;
    cout.flush();
    return ; 
}
void mkq2(int l, int r, int p) {
    cout << '?' << ' ' << (r - l + 1) + 1 << ' ';
    for (int i = l; i <= r; i++) cout << i << ' ';
    cout << p << '\n';
    cout.flush();
    cin >> res;
    cout.flush();
    return ;
}
void solve() {
    cin >> n;
    int l, r, mid, rp, lp, ans;
    l = 3, r = 2 * n + 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        mkq1(1, mid);
        if ((mid - res) % 2 == 0) l = mid + 1;
        else rp = mid, r = mid - 1;
    }
    l = 1, r = rp - 2;
    while (l <= r) {
        mid = (l + r) >> 1;
        mkq1(mid, rp);
        if ((rp - mid + 1 - res) % 2 == 0) r = mid - 1;
        else lp = mid, l = mid + 1;
    }
    l = lp + 1, r = rp - 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        mkq2(lp, mid, rp);
        if ((mid - lp + 2 - res) % 2 == 0) l = mid + 1;
        else ans = mid, r = mid - 1;
    }
    cout << '!' << ' ' << lp << ' ' << ans << ' ' << rp << '\n';
    cout.flush();
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}