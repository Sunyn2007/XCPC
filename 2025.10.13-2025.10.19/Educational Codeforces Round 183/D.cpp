#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int t, n, k, p[N + 5], ans[N + 5];
bool flag;
void rev(int l, int r) {
    while (l < r) {
        swap(p[l], p[r]);
        l += 1, r -= 1;
    }
    return ;
}
void dfs(int now, int step, int k) {
    if (flag) return ;
    if (!k) {
        flag = true;
        for (int i = 1; i <= n; i++) ans[i] = p[i];
        return ;
    }
    if (step == 1 || now > n) return ;
    if (now + step - 1 <= n && k >= step * (step - 1) / 2) {
        rev(now, now + step - 1);
        dfs(now + step, step, k - step * (step - 1) / 2);
        rev(now, now + step - 1);
    }
    dfs(now, step - 1, k);
    return ;
}
void solve() {
    cin >> n >> k, k = n * (n - 1) / 2 - k;
    for (int i = 1; i <= n; i++) p[i] = n - i + 1;
    flag = false, dfs(1, n, k);
    if (flag) {
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    else cout << 0 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}