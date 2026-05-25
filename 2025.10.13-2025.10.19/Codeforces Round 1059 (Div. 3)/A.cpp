#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    cout << maxn << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}