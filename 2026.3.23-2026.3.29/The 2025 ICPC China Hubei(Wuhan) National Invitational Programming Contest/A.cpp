#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9 + 1;
int t, n, q, a[N + 5];
pair<int, int> s[N + 5]; 
pair<int, int> syn(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.second || a.second < b.first) return make_pair(INF, -INF);
    else return make_pair(max(a.first, b.first), min(a.second, b.second));
}
int abs(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], s[i].first = -INF, s[i].second = INF;
    for (int i = 1; i <= q; i++) {
        int p, l, r;
        cin >> p >> l >> r;
        s[p] = syn(s[p], make_pair(l, r));
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i].first == INF) {
            ans = -1;
            break;
        }
        if (a[i] < s[i].first || a[i] > s[i].second) 
            ans += min(abs(s[i].first - a[i]), abs(s[i].second - a[i]));
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