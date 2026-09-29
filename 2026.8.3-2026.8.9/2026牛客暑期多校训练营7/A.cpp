#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
bool bk[N + 5];
int gb(int x, int k) {
    return (x >> k - 1) & 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0, cnt = 0;
    for (int i = 30; i >= 1; i--) {
        vector<int> p01, p10;
        for (int j = 2; j <= n; j++) {
            if (!gb(a[j - 1], i) && gb(a[j], i))
                p01.push_back(j - 1);
            if (gb(a[j - 1], i) && !gb(a[j], i))
                p10.push_back(j - 1);
        }
        if (!p10.empty()) {
            int mx = 0, tot;
            for (int l = 0; l < n + 1;) {
                int r = l + 1;
                while (a[r] != )
            }
        }
        else for (auto p : p01) bk[p] = true;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) bk[i] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}