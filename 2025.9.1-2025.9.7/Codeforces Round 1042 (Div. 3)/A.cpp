#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int t, n, a[N + 5], b[N + 5];
void solve() {
    int tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (a[i] > b[i]) tot += a[i] - b[i];
    }
    cout << tot + 1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}