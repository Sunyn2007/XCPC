#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], b[N + 5], cnt;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);    
    int now = 1, tot = 0;
    long long sum = 0;
    cnt = 0;
    while (now < n) {
        if (a[now] == a[now + 1]) sum += a[now] * 2, tot += 2, now += 2;
        else b[++cnt] = a[now], now += 1;
    }
    if (now == n) b[++cnt] = a[now];
    if (cnt == 0) {
        if (tot > 2) cout << sum;
        else cout << 0;
    }
    else if (cnt == 1) {
        if (sum > b[1]) cout << sum + b[1];
        else if (tot > 2) cout << sum;
        else cout << 0;
    }
    else {
        long long ans = (tot > 2 ? sum : 0);
        for (int i = 0, j = 0; i < cnt; i++) {
            if (j < i) j = i;
            while (j + 1 <= cnt && b[i] + sum > b[j + 1]) j += 1;
            if (i != j) ans = b[i] + b[j] + sum;
        }
        cout << ans;
    }
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