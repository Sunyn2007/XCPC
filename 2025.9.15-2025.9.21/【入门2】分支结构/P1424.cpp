#include <bits/stdc++.h>
using namespace std;
int x, n, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> x >> n;
    while (x + n - 1 > 7) {
        if (x <= 5) ans += (5 - x + 1) * 250;
        n -= (7 - x + 1);
        x = 1;
    }
    if (x + n - 1 > 5) ans += 5 * 250;
    else ans += (x + n - 1) * 250;
    cout << ans;
    return 0;
}