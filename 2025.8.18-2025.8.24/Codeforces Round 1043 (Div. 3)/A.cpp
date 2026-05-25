#include <bits/stdc++.h>
using namespace std;
int t, n, m;
string a, b, c;
void solve() {
    cin >> n >> a >> m >> b >> c;
    for (int i = 0; i < m; i++) {
        if (c[i] == 'D') a = a + b[i];
        else a = b[i] + a;
    }
    cout << a << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}