#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
vector<int> ans;
void solve() {
    cin >> n >> s, s = ' ' + s;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0') ans.push_back(i);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
    ans.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}