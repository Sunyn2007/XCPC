#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 5e5, INF = 0x3f3f3f3f;
struct edge {
    int to, nxt;
}e[2 * M + 5];
int head[N + 5], cnt;
int t, n, m, d, k, dis1[N + 5][2], dis2[N + 5][2];
pair<int, int> pre[N + 5][2];
bool tag[N + 5][2];
vector<int> s, ans;
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void bfs1() {
    for (int i = 1; i <= n; i++) dis1[i][0] = dis1[i][1] = INF, tag[i][0] = tag[i][1] = 0;
    queue<pair<int, int> > q;
    for (auto x : s) {
        dis1[x][0] = 0;
        q.push(make_pair(x, 0));
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        tag[x][y] = true;
        if (dis1[x][y] == d) continue;
        for (int i = head[x]; i; i = e[i].nxt) {
            int to = e[i].to;
            if (dis1[to][1 - y] == INF) {
                dis1[to][1 - y] = dis1[x][y] + 1;
                q.push(make_pair(to, 1 - y));
            }
        }
    }
    return ;
}
void bfs2() {
    for (int i = 1; i <= n; i++) dis2[i][0] = dis2[i][1] = INF, pre[i][0] = pre[i][0] = make_pair(0, 0);
    queue<pair<int, int> > q;
    dis2[1][0] = 0;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].nxt) {
            int to = e[i].to;
            if (dis2[to][1 - y] == INF) {
                if (tag[to][1 - y] && dis2[x][y] + 1 >= dis1[to][1 - y]) continue;
                dis2[to][1 - y] = dis2[x][y] + 1;
                pre[to][1 - y] = make_pair(x, y);
                q.push(make_pair(to, 1 - y));
            }
        }
    }
    if (dis2[n][0] == INF && dis2[n][1] == INF) return ;
    pair<int, int> x;
    if (dis2[n][0] <= dis2[n][1]) x = make_pair(n, 0);
    else x = make_pair(n, 1);
    while (x.first) {
        ans.push_back(x.first);
        x = pre[x.first][x.second];
    }
    reverse(ans.begin(), ans.end());
    return ;
}
void solve() {
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }
    bfs1(), bfs2();
    if (ans.empty()) cout << -1 << '\n';
    else {
        cout << ans.size() - 1 << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    s.clear(), ans.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}