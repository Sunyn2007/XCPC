#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    int ans = 0X7fffffff;
    while (n >= 0) {
        ans = min(ans, n % 3);
        ans = min(ans, n % 5);
        n -= 8;
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