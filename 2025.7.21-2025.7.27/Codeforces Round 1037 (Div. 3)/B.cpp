#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, k, a[N + 5];
void solve() {
    int ans = 0, now = 1, tmp = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (now <= n) {
        if (a[now]) tmp = 0;
        else tmp += 1;
        if (tmp == k) 
            ans += 1, tmp = 0, now += 2;
        else now += 1;
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}