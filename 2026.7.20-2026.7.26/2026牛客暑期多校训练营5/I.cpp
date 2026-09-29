#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int t, n, ans[1 << N];
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    int len = (1 << n) - 1;
    for (int i = 1; i < len; i++)
        if (s[i] == '1') ans[len ^ i] = i;
    for (int i = 1; i <= len; i++)
        cout << ans[len] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) ans[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}