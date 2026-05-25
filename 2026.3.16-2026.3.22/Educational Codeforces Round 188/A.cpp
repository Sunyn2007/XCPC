#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    int ans;
    for (int i = 1; i <= n; i++) {
        ans = i;
        if (s[i] == 'L') break;
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