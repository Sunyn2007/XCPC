#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5][N + 5], book[N * N + 5];
void solve() {
    bool flag = true;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            book[a[i][j]] += 1;
            if (book[a[i][j]] > n * n - n) flag = false;
        }
    if (flag) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    for (int i = 1; i <= n * n; i++)
        book[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}