#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
vector<int> ans;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool tag = false;
    for (int i = n; i >= 1; i--) {
        if (a[i] > 0 && !tag) ans.push_back(i), tag = !tag;
        if (a[i] < 0 && tag) ans.push_back(i), tag = !tag;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
    ans.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}