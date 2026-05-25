#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int t, n, a[(N << 1) + 5], b[(N << 1) + 5], c[(N << 1) + 5];
bool check(int a[], int b[], int x, int y) {
    for (int i = 1; i <= n; i++)
        if (a[x + i - 1] >= b[y + i - 1]) return false;
    return true;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], b[i + n] = b[i];
    for (int i = 1; i <= n; i++) cin >> c[i], c[i + n] = c[i];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
        if (check(a, b, 1, i)) cnt1 += 1;
    for (int i = 1; i <= n; i++)
        if (check(b, c, 1, i)) cnt2 += 1;
    cout << 1ll * n * cnt1 * cnt2 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}