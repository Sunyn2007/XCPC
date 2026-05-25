#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, sn, a[N + 5];
void solve() {
    cin >> n, sn = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > sn) {
            for (int j = i - a[i]; j >= 1; j -= a[i]) 
                if ((i - j) / a[i] == a[j]) ans += 1;
            for (int j = i + a[i]; j <= n; j += a[i])
                if ((j - i) / a[i] == a[j]) ans += 1;
        }
        else {
            for (int j = 1; j <= sn; j++)
                if (i - j * a[i] >= 1 && a[i - j * a[i]] == j) ans += 1;
        }
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