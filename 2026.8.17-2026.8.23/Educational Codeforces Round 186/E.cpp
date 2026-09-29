#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 2e5;
int t, n, m;
long long k;
bool bk[N + 5];
multiset<int> s;
struct syn {
    int x, y, z;
}a[N + 5];
bool cmp(syn a, syn b) {
    return a.z - a.y < b.z - b.y;
}
void solve() {
    int ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z, k -= a[i].y;
    sort(a + 1, a + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
        auto it = s.lower_bound(a[i].x);
        if (it != s.end()) s.erase(it), bk[i] = true, ans += 1;
    }
    for (int i = 1; i <= n; i++)
        if (!bk[i] && k >= a[i].z - a[i].y)
            k -= a[i].z - a[i].y, ans += 1;
    cout << ans << '\n';
    s.clear();
    for (int i = 1; i <= n; i++) bk[i] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}