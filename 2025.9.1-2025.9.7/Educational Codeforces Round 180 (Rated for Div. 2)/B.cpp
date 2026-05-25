#include <bits/stdc++.h>
using namespace std;
const int N = 1000, V = 1e6;;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = N;
    for (int i = 1; i <= n; i++) {
        int maxn = 0, minn = V + 1;
        for (int j = i - 1; j >= 1; j--) {
            maxn = max(maxn, a[j]), minn = min(minn, a[j]);
            if (maxn >= a[i] - 1 && minn <= a[i] + 1) ans = min(ans, i - j - 1);
        }
        maxn = 0, minn = V + 1;
        for (int j = i + 1; j <= n; j++) {
            maxn = max(maxn, a[j]), minn = min(minn, a[j]);
            if (maxn >= a[i] - 1 && minn <= a[i] + 1) ans = min(ans, j - i - 1);
        }
    }
    cout << (ans == N ? -1 : ans) << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}