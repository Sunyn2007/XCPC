#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, n, m, q, fa[N], h[N], ans[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) fa[rx] = ry;
}
struct Edge {
    int u, v, max_h;
    bool operator<(const Edge& o) const { return max_h < o.max_h; }
} edges[N];
struct Query {
    int a, b, id;
    long long limit;
    bool operator<(const Query& o) const { return limit < o.limit; }
} queries[N];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].max_h = max(h[edges[i].u], h[edges[i].v]);
    }
    sort(edges, edges + m);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        long long e;
        cin >> a >> b >> e;
        queries[i] = {a, b, i, h[a] + e};
    }
    sort(queries, queries + q);
    int idx = 0;
    for (int i = 0; i < q; ++i) {
        while (idx < m && edges[idx].max_h <= queries[i].limit) {
            unite(edges[idx].u, edges[idx].v);
            idx++;
        }
        ans[queries[i].id] = (find(queries[i].a) == find(queries[i].b));
    }
    for (int i = 0; i < q; ++i) cout << (ans[i] ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}