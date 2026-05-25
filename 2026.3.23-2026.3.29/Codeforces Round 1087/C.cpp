#include <bits/stdc++.h>
using namespace std;
int t, n, res;
void mkq(int i, int j) {
    cout << '?' << ' ' << i << ' ' << j << '\n', cout.flush();
    cin >> res, cout.flush();
    return ;
}
void syn(int i) {
    cout << '!' << ' ' << i << '\n', cout.flush();
    return ;
}
void solve() {
    cin >> n;
    bool ok = false;
    for (int i = 3; i <= n; i++) {
        mkq(2 * i - 1, 2 * i);
        if (res == 1) {
            ok = true;
            syn(2 * i - 1);
            break;
        }
    }
    if (!ok) {
        mkq(1, 2);
        if (res == 1) syn(1);
        else {
            mkq(2, 3);
            if (res == 1) syn(2);
            else {
                mkq(1, 3);
                if (res == 1) syn(1);
                else syn(4);
            }
        }
    }
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}