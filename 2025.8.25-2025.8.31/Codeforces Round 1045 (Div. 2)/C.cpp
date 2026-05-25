#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], b[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i += 2) {
        if (i == 1) b[i] = min(a[i], a[i + 1]);
        else if (i == n) b[i] = min(a[i], a[i - 1] - b[i - 2]);
        else {
            int x = a[i - 1] - b[i - 2];
            if (x < a[i] && x < a[i + 1]) b[i] = x;
            else b[i] = min(a[i], a[i + 1]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i += 2) 
        ans += a[i] - b[i];
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}