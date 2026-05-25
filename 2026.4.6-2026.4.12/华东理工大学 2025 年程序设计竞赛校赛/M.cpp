#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    int num = (1 << 29);
    for (int i = 1; i <= n; i++)
        cout << num++ << ' ';
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}