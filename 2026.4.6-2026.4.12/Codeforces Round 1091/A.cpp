#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5], k;
void solve() {
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], sum += a[i];
    if (sum % 2 == 1 || n * k % 2 == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}