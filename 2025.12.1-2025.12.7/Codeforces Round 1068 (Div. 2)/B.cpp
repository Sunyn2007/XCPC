#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, a[N + 5], b[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    long long minn = 0, maxn = 0;
    for (int i = 1; i <= n; i++) {
        long long tmin = min(minn - a[i], b[i] - maxn);
        long long tmax = max(maxn - a[i], b[i] - minn);
        minn = tmin, maxn = tmax;
    }
    cout << maxn << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}