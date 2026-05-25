#include <bits/stdc++.h>
using namespace std;
const int M = 2e5, K = 2e5;
int t, n, m, k, x[K + 5], y[K + 5], a[M + 5];
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i];
        a[y[i]] += 1;
    }
    if (m == 1) cout << "Yuyu" << '\n';
    else if (n == 1) {
        if (a[2] % 2 == 1) cout << "Mimo" << '\n';
        else cout << "Yuyu" << '\n';
    }
    else {
        bool flag = false;
        for (int i = 1; i <= k; i++) 
            if (y[i] > 1 && a[y[i]] % 2 == 1) {
                flag = true;
                break;
            }
        if (flag) cout << "Mimo" << '\n';
        else cout << "Yuyu" << '\n';
    }
    for (int i = 1; i <= k; i++)
        a[y[i]] -= 1;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}