#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    if (n == 2) cout << "YES" << '\n';
    else {
        bool fl = true;
        for (int i = 2; i <= n; i++)
            if ((n + 1) % i == 0) fl = false;
        if (fl) cout << "YES" << '\n';
        else cout << "NO" << '\n';
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