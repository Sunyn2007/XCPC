#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += max(x, 1);
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}