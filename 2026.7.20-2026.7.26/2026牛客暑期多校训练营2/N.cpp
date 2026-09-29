#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5];
long long s[N + 5];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    long long ans = 0;
    if (k % 2 == 1) {
        int len = k / 2;
        for (int i = len + 1; i <= n - len; i++)
            ans = max(ans, s[n] - s[len] - (s[i + len] - s[i - 1]) + 1ll * a[i] * k);
    }
    else {
        int len = k / 2;
        for (int i = len + 1; i <= n - len + 1; i++)
            ans = max(ans, s[n] - (s[i + len - 1] - s[i - 2]) - s[len - 1] + 1ll * (a[i] + a[i - 1]) * k / 2);
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve(); 
    return 0;
}