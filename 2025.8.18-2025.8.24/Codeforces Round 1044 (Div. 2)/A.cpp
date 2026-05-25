#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5];
void solve () {
    bool ans = false;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) 
        if (a[i] == a[i - 1]) ans = true;
    cout << (ans ? "Yes" : "No") << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}