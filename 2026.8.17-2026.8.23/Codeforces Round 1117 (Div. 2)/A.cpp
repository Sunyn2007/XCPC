#include <bits/stdc++.h>
using namespace std;
int t, n, m;
bool bk[256];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        bk[s[0]] = true;
    }
    bool ans = true;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        for (auto ch : s) 
            if (!bk[ch - 'A' + 'a']) ans = false;
    }
    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    memset(bk, 0, sizeof(bk));
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}