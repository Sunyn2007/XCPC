#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n;
long long k, a[N + 5];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (k == 1) {
        for (int i = 1; i <= n; i++)
            if (a[i] % 2 == 1) a[i] += k;
    }
    else if (k == 2) {
        for (int i = 1; i <= n; i++) {
            if (a[i] % 3 == 1) a[i] += k;
            if (a[i] % 3 == 2) a[i] += 2 * k;
        }
    }
    else {
        for (int i = 1; i <= n; i++)
            a[i] += ((k - 1) - a[i] % (k - 1)) * k;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}