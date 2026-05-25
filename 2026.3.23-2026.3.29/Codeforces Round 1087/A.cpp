#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, k, a[N + 5];
long long c;
void solve() {
    cin >> n >> c >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (c >= a[i]) {
            if (a[i] + k <= c) c += a[i] + k, k = 0;
            else k -= c - a[i], c += c;
        }
        else break;
    }
    cout << c << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}