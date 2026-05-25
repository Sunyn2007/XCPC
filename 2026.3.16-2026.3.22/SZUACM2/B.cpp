#include <bits/stdc++.h>
using namespace std;
int t, n, m;
string a, b;
void solve() {
    cin >> a >> b, n = a.size(), m = b.size();
    a = ' ' + a, b = ' ' + b;
    int ans = n + m;
    for (int i = 1; i <= m; i++) {
        int now = i;
        for (int j = 1; j <= n; j++)
            if (b[now] == a[j]) now += 1;
        ans = min(ans, n + m - (now - i));   
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