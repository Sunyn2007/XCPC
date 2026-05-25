#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], b[N + 5];
bool check(int x) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x && b[i] >= x) cnt1 += 1;
        if (a[i] < x && b[i] < x) cnt2 += 1;
    }
    if (!cnt2) {
        if (cnt1) return true;
        else return false;
    }
    else {
        if (cnt1 == 1) return false;
        else {
            int cnt = 0;
            bool flag = false;
            for (int i = 1; i <= n; i++) {
                if (a[i] >= x && b[i] >= x) flag = false;
                if (a[i] < x && b[i] < x && !flag) cnt += 1, flag = true;
            }
            if (cnt < cnt1) return true;
            else return false;
        }
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int l = 1, r = 2 * n, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
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