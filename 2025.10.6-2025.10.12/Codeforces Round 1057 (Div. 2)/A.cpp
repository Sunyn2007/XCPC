#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5], book[N + 5];
void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!book[a[i]]) ans += 1;
        book[a[i]] = true;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        book[a[i]] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}