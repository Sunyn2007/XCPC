#include <bits/stdc++.h>
using namespace std;
int t, res;
void mkq(int a, int b) {
    cout << '?' << ' ' << a << ' ' << b << '\n';
    cout.flush();
    cin >> res;
    cout.flush();
    return ;
}
void solve() {
    int ans = 0;
    for (int i = 0; i <= 29; i++) {
        mkq((1 << i + 1) + (1 << i) - ans, (1 << i) - ans);
        if (res != (1 << i)) ans += (1 << i);
    }
    cout << '!' << ' ' << ans << '\n';
    cout.flush();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}