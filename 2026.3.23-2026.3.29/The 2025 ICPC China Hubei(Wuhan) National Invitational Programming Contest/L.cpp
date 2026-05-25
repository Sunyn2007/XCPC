#include <bits/stdc++.h>
using namespace std;
const int N = 3e3;
int t, n, a[N + 5];
map<int, int> fst, lst;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (fst.find(a[i]) == fst.end()) fst[a[i]] = i;
        lst[a[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            if ((a[i] + a[j]) % 2) continue;
            int x = (a[i] + a[j]) / 2;
            if (fst.find(x) == fst.end()) continue;
            int l = fst[x], r = lst[x], p = (i + j) / 2;
            if (p > r) ans = max(ans, (r - i + 1) * 2);
            else if (p < l) ans = max(ans, (j - l + 1) * 2 - 1);
            else {
                if ((j - i + 1) % 2 == 0) ans = max(ans, (p - i + 1) * 2);
                else ans = max(ans, (p - i + 1) * 2 - 1);
            }
        }
    cout << ans << '\n';
    fst.clear(), lst.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}