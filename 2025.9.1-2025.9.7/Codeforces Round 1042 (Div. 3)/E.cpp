#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], b[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    bool flag = true;
    for (int i = n; i >= 1; i--) {
        if (a[i] != b[i]) {
            if (i == n) flag = false;
            if ((a[i] ^ a[i + 1]) != b[i] && (a[i] ^ b[i + 1]) != b[i]) flag = false;
        }
        if (!flag) break;
    }
    cout << (flag ? "Yes" : "No") << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}