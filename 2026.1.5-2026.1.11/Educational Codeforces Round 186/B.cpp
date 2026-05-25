#include <bits/stdc++.h>
using namespace std;
int t, a, b;
bool check(int a, int b, int x, int y) {
    if (a > b) swap(a, b);
    if (x > y) swap(x, y);
    if (x <= a && y <= b) return true;
    else return false;
}
void solve() {
    cin >> a >> b;
    int ans = 0, now = 0, tot0 = 0, tot1 = 0;
    while (check(a, b, tot0, tot1)) {
        if (!now) tot0 += (1 << ans);
        else tot1 += (1 << ans);
        ans += 1, now ^= 1;
    }
    cout << ans - 1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}