#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, MX = 1e9;
int t, n, a[N + 5];
void solve() {
    int mn;
    bool ans = true;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    mn = a[1];
    for (int i = 2; i <= n && ans; i++) {
        if (a[i] > mn) {
            if (a[i] > (mn << 1) - 1) ans = false;
            else continue;
        }
        else mn = a[i];
    }
    cout << (ans ? "Yes" : "No") << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}