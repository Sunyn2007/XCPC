#include <bits/stdc++.h>
using namespace std;
int t, a, b;
vector<int> ans;
void solve() {
    cin >> a >> b;
    bool ok = true;
    for (int i = 0; i <= 30; i++) {
        int ba = (a >> i) & 1, bb = (b >> i) & 1;
        if (ba != bb) {
            int x = 1 << i;
            if ((1 << i) > a) ok = false;
            a ^= x;
            ans.push_back(1 << i);
        }
    }
    if (!ok) cout << -1 << '\n';
    else {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
           cout << ans[i] << ' ';
        if (ans.size()) cout << '\n';
    }
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