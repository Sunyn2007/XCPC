#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, k, h[N + 5];
void solve() {
    int now, tmp = 0, maxh = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> h[i], maxh = max(maxh, h[i]);
    now = h[k];
    sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; i++)
        if (h[i] > now) {
            if (tmp + h[i] - now <= now)
                tmp += h[i] - now, now = h[i];
            else break;
        }
    if (now == maxh) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}