#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n;
void solve() {
    cin >> n;
    int ans = 0, maxn = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x >= maxn) 
            maxn = x, ans += 1;
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