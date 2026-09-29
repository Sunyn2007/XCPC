#include <bits/stdc++.h>
using namespace std;
const int M = 2e5;
struct syn{
    int l, r;
}a[M + 5];
int t, n, m;
bool cmp(syn a, syn b) {
    if (a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}
void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) 
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + m + 1, cmp);
    int ans = n;
    set<pair<int, int> > s;
    s.insert(make_pair(1, n));
    for (int i = 1; i <= m; i++) {
        if (a[i].l == a[i].r) continue;
        auto it1 = s.lower_bound(make_pair(a[i].l, a[i].l)), it2 = it1;
        if (it1 != s.begin()) {
            it1--;
            if ((*it1).second >= a[i].l) {
                ans -= 1;
                int l = (*it1).first, r = (*it1).second;
                s.erase(it1), s.insert(make_pair(l, a[i].l - 1));
                if (a[i].l < r) s.insert(make_pair(a[i].l + 1, r));
                continue;
            }
        }
        if (it2 != s.end() && (*it2).first < a[i].r) {
            ans -= 1;
            int l = (*it2).first, r = (*it2).second;
            s.erase(it2);
            if (l < r) s.insert(make_pair(l + 1, r));
        }
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}