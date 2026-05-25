#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
long long s[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], s[i] = s[i - 1] + a[i];
    long long ans = -0x7fffffffffffffff, tmp = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, tmp - (s[n] - s[i]));
        if (i == 1) tmp += a[i];
        else tmp += max(a[i], -a[i]);
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