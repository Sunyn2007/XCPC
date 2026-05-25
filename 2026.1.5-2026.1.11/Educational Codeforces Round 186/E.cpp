#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 2e5;
struct syn{
    int id, x, y, z;
}b[N + 5];
int t, n, m, a[M + 5];
long long k;
bool book[N + 5];
multiset<int> s;
priority_queue<pair<int, int> > q1, q2;
bool cmp(syn a, syn b) {
    return a.z < b.z;
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> a[i], s.insert(a[i]);
    for (int i = 1; i <= n; i++) cin >> b[i].x >> b[i].y >> b[i].z, b[i].id = i;
    sort(b + 1, b + n + 1, cmp);
    int now = 1, ans = 1;
    while (k >= b[now].z) {
        book[now] = true;
        k -= b[now].z;
        q1.push(make_pair(-(b[now].z - b[now].y), now));
        now += 1;
    }
    for (int i = now; i <= n; i++) q2.push(make_pair(-(b[now - 1].z - b[i].y), i));
    while ((!q1.empty() || !q2.empty()) && !s.empty()) {
        int d1 = 0, d2 = 0, id1, id2;
        if (!q1.empty()) d1 = -q1.top().first, id1 = q1.top().second;
        if (!q2.empty()) d2 = -q2.top().first, id2 = q2.top().second;
        if (d1 <= 0 && d2 <= 0) break;
        if (d1 >= d2) {
            auto it = s.lower_bound(b[id1].x);
            if (it != s.end()) k += d1;
            q1.pop();
        }
        else {
            auto it = s.lower_bound(b[id2].x);
            if (it != s.end()) k += d2, book[id2] = true;
            q2.pop();
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}