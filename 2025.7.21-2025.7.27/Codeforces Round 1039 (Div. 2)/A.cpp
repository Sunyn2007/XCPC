#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int t, n, c, a[N + 5], tmp[N + 5];
void solve() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp[i] = 0;
        while (a[i] <= c)
            a[i] <<= 1, tmp[i] += 1;
    }
    sort(tmp + 1, tmp + n + 1);
    int res = 0, now = 0;
    for (int i = 1; i <= n; i++) {
        if (tmp[i] <= now) res += 1;
        else now += 1;
    } 
    cout << res << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}