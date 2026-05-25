#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
    int n, ans = 9;
    cin >> n;
    while (n) {
        int x = n % 10;
        ans = min(ans, x);
        n /= 10;
    }
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