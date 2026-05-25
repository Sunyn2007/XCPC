#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
struct data {
    int l, r, val;
    bool operator<(const data &x) const {
        if (l == x.l) return r < x.r;
        return l < x.l;
    }
}a[N + 5];
int t, n, k;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i].l >> a[i].r >> a[i].val;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        if (k >= a[i].l && k <= a[i].r)
            k = max(k, a[i].val);
    cout << k << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}