#include <bits/stdc++.h>
using namespace std;
int t, a, b;
void solve() {
    cin >> a >> b;
    if (b <= a + 1) {
        if (b < a) {
            if ((a - b) % 2 == 0) cout << a << '\n';
            else cout << a + 1 << '\n';
        }
        else if (b == a) cout << a << '\n';
        else cout << a + 1 << '\n';
    }
    else cout << -1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}