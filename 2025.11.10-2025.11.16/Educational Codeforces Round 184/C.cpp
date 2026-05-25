#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
long long s[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], s[i] = s[i - 1] + a[i];
    long long maxn = -0x7fffffffffffffff, res = 0;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, 1ll * i * (1 - i) + s[i - 1]);
        res = max(res, 1ll * i * (i + 1) - s[i] + maxn);
    }
    cout << s[n] + res << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}