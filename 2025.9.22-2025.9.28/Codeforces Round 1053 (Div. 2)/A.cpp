#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 200;
int t, n, m, a[M + 5], book[N + 5];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) 
        cin >> a[i], book[a[i]] += 1;
    if (a[1] == 1) {
        if (book[1] == 1) cout << n - (m - 1) << '\n';
        else cout << 1 << '\n';
    }
    else {
        if (book[1] == 0) cout << n - (a[m] - 1) << '\n';
        else cout << 1 << '\n';
    }
    for (int i = 1; i <= m; i++) book[a[i]] -= 1;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}