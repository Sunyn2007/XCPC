#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, bk[N + 5];
void solve() {
    cin >> n;
    int pre = 0;
    for (int i = 0; i <= n; i++) {
        int x;
        cin >> x;
        pre ^= x;
        if (pre == 0) {
            if (i == n) bk[0] += 1;
            bk[n - i - 1] += 1;
        }
    }
    for (int i = 0; i < n; i++)
        bk[i + 1] += bk[i] / 2, bk[i] %= 2;
    bool flag = false;
    for (int i = n; i >= 0; i--) {
        if (bk[i]) flag = true;
        if (flag) cout << bk[i];
    }
    if (!flag) cout << 0;
    cout << '\n';
    for (int i = 0; i <= n; i++) bk[i] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}