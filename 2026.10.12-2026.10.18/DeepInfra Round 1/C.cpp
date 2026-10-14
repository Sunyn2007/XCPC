#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> ans;
    ans.push_back(0);
    int now = 1;
    while (n) {
        vector<int> tmp = ans;
        ans.push_back(now);
        for (auto x : tmp) ans.push_back(x);
        n >>= 1, now <<= 1;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}