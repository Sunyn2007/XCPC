#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, l, r, sl, n, a[N + 5];
long long ans;
int bct(int x, int bt) {
    return (x >> bt - 1) & 1;
}
void dfs(int l, int r, int bt) {
    if (l == r) {
        a[l - sl + 1] = l;
        ans += l;
        return ;
    }
    if (bct(l, bt) || !bct(r, bt))
        dfs(l, r, bt - 1);
    else {
        int p1 = l, p2;
        while (!bct(p1 + 1, bt)) p1 += 1;
        p2 = p1 + 1;
        while (p1 >= l && p2 <= r)  {
            a[p1 - sl + 1] = p2, a[p2 - sl + 1] = p1;
            ans += (p1 | p2) << 1, p1 -= 1, p2 += 1;
        }
        if (p1 >= l) dfs(l, p1, bt - 1);
        if (p2 <= r) dfs(p2, r, bt - 1);
    }
    return ;
}
void solve() {
    ans = 0;
    cin >> l >> r, sl = l, n = r - l + 1;
    dfs(l, r, 30);
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
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