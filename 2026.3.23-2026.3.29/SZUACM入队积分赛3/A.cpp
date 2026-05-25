#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5], b[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(a + 1, a + n + 1);
    if (a[1] == a[n]) cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) {
            if (b[i] == a[n]) cout << 2 << ' ';
            else cout << 1 << ' ';
        }
        cout << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}