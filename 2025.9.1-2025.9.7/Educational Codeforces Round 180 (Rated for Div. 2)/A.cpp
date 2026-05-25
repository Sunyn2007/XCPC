#include <bits/stdc++.h>
using namespace std;
int t, a, x, y;
int syn(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> a >> x >> y;
    if (x > y) swap(x, y);
    if (x <= a && a <= y) cout << "No" << "\n";
    else cout << "Yes" << "\n";
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}