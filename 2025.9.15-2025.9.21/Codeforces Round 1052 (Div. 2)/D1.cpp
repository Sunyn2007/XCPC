#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, l, r, n, a[N + 5], pos[N + 5];
void dfs(int l, int r) {
    int len = r - l + 1;
    if (len == 2) {
        swap(a[l], a[r]);
        return ;
    }
    if (len == 1) return ;
    int cnt = 0, mid, bcnt = 0;
    while (len) {
        if (len & 1) bcnt += 1;
        len >>= 1;
        cnt += 1;
    }
    if (bcnt == 1) cnt -= 1;
    mid = l + (1 << cnt - 1) - 1;
    dfs(l, mid), dfs(mid + 1, r);
    for (int i = l, j = mid + 1; j <= r; i++, j++) 
        swap(a[i], a[j]);
    return ;
}
void solve() {
    cin >> l >> r;
    for (int i = 0; i <= r; i++) a[i] = i;
    dfs(l, r);
    long long ans = 0;
    for (int i = 0; i <= r; i++) ans += a[i] | i;
    cout << ans << '\n';
    for (int i = 0; i <= r; i++) cout << a[i] << ' ';
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
