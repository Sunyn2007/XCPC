#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int t, n, a[N + 5], b[N + 5], r[N + 5];
set<int> s1[N + 5], s2[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) s1[a[i]].insert(i);
        else s2[a[i]].insert(i), s2[b[i]].insert(i);
    }
    for (int i = n; i >= 1; i--) {
        for (auto it = s1[i].begin(); it != s1[i].end(); it++) {
            auto it1 = s1[i + 1].upper_bound(*it);
            int r1 = (it1 == s1[i + 1].end() ? n + 1 : *it1);
            auto it2 = s2[i + 1].upper_bound(*it);
            int r2 = (it2 == s2[i + 1].end() ? n + 1 : *it2);
            if (r1 == n + 1) {
                if (r2 == n + 1) r[*it] = n;
                else r[*it] = r2 - 1;
            }
            else {
                if (r2 == n + 1 || r2 > r1) r[*it] = r[r1];
                else r[*it] = r2 - 1;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int resr;
        auto it1 = s1[1].lower_bound(i);
        int r1 = (it1 == s1[1].end() ? n + 1 : *it1);
        auto it2 = s2[1].lower_bound(i);
        int r2 = (it2 == s2[1].end() ? n + 1 : *it2);
        if (r1 == n + 1) {
            if (r2 == n + 1) resr = n;
            else resr = r2 - 1;
        }
        else {
            if (r2 == n + 1 || r2 > r1) resr = r[r1];
            else resr = r2 - 1;
        }
        ans += resr - i + 1;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) s1[i].clear(), s2[i].clear(), r[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}