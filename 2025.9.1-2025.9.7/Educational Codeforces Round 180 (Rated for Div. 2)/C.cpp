#include <bits/stdc++.h>
using namespace std;
const int N = 5000, V = 1e5;
int t, n, a[N + 5], s[V + 5];
void solve() {
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            for (int j = a[i - 1] + 1; j <= a[i]; j++) 
                s[j] = s[j - 1];
        }
        s[a[i]] += 1;
        int v = a[i] <= a[n] / 2 ? a[n] - a[i] + 1 : a[i] + 1, res = 0;
        for (int j = 1; j <= i - 1; j++) {
            int minn = max(v - a[j], 1);
            if (minn <= a[i]) {
                if (minn > a[j]) res += s[a[i]] - s[minn - 1] - 1;
                else res += s[a[i]] - s[minn - 1] - 2;
            }
        } 
        ans += res / 2;
    }
    cout << ans << '\n';
    for (int i = 1; i <= a[n]; i++) s[i] = 0; 
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}