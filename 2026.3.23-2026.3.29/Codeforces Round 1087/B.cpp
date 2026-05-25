#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] > a[i]) cnt1 += 1;
            if (a[j] < a[i]) cnt2 += 1;
        }
        cout << max(cnt1, cnt2) << ' ';
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}