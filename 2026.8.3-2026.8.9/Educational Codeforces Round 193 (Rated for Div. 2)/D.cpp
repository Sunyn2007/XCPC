#include <bits/stdc++.h>
using namespace std;
int t, n, x, y;
void solve() {
    cin >> x >> y;
    int n = 1;
    while ((n + 1) * (n + 2) <= 2 * (x + y)) n += 1;
    int s = x + y - n * (n + 1) / 2, a, b;
    if (s % 2 == 0) a = s / 2, b = s / 2;
    else a = s / 2 + 1, b = s / 2;
    while (a > x || b > y) {
        if (x > y) a += 1, b -= 1;
        else a -= 1, b += 1;
    }
    a = x - a, b = y - b;
    //cout << a << ' ' << b << '\n';
    string ans;
    int now = 0, sx = 0, sy = 0, dx = 0, dy = 0;
    while (sx < a || sy < b) {
        if (sy + (n - now) * (dy + 1) <= b) ans += 'Y', dy += 1;
        else ans += 'X', dx += 1;
        now += 1, sx += dx, sy += dy;
        //cout << sx << ' ' << sy << '\n';
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}