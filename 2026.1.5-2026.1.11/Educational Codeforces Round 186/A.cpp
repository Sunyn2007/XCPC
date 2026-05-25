#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    bool flag1 = false, flag2 = false;
    for (int i = 1; i <= n - 3; i++)
        if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2') {
            if (s[i + 3] == '6') flag1 = true;
            if (s[i + 3] == '5') flag2 = true;
        }
    if (flag1) cout << 0 << '\n';
    else if (flag2) cout << 1 << '\n';
    else cout << 0 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}