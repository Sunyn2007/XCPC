#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    int w = n, l = 0, ans = 0;
    while (w != l || w != 1 || l != 1) {
        int tmp = w / 2;
        ans += w / 2 + l / 2;
        if (w % 2 == 0) w /= 2;
        else w = w / 2 + 1;
        if (l % 2 == 0) l /= 2;
        else l = l / 2 + 1;
        l += tmp;
    }
    ans += 1;
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
4 0
2 2
1 2
1 1
*/