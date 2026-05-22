#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, c[N + 5];
void solve() {
    cin >> n;
    long long sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i], sum += c[i];
        if (c[i] > 1) cnt += 1;
    }
    sort(c + 1, c + n + 1);
    if (sum < 3 || cnt == 0) {
        cout << 0 << '\n';
        return ;
    }
    long long ans = 0, tmp = 0;
    for (int i = n; i >= 1; i--) {
        if (c[i] > 1) {
            ans += c[i];
            if (cnt == 1) tmp += c[i] / 2;
            else tmp += (c[i] - 2) / 2;
        }
        else if (tmp) ans += 1, tmp -= 1;
    }
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