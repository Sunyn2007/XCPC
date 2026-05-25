#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> s, s = ' ' + s;
    int cnt = 0;
    for (int i = 1; i <= s.size(); i++)
        if (s[i] == 'Y') cnt += 1;
    if (cnt >= 2) cout << "NO" << '\n';
    else cout << "YES" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}