#include <bits/stdc++.h>
using namespace std;
int t, n, k;
map<int, int> bk;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bk[x] += 1;
    }
    bool flag = false;
    for (int i = 0; i <= n; i++) {
        if (bk[i] < 2 * k - 1) break;
        if (bk[i] == 2 * k - 1) flag = true;
    }
    if (flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    bk.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}