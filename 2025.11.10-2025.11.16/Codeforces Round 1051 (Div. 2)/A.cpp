#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5], pos[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], pos[a[i]] = i;
    int l = pos[n], r = pos[n];
    bool ok = true;
    for (int i = n - 1; i >= 1; i--) {
        if (pos[i] == r + 1) r += 1;
        else if (pos[i] == l - 1) l -= 1;
        else ok = false;
    }
    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}