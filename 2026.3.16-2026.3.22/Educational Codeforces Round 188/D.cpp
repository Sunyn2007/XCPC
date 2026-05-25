#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 2e5;
struct edge {
    int to, nxt;
}e[(M << 1) + 5];
int cnt, head[N + 5];
int t, n, m, col[N + 5];
bool vis[N + 5], flag;
vector<int> a;
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs(int x) {
    vis[x] = true;
    a.push_back(x);
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (vis[y]) {
            if (col[y] == col[x]) flag = true;
        }
        else {
            if (col[x] == 1) col[y] = 2;
            else col[y] = 1;
            dfs(y);
        }
    }
    return ;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            flag = false;
            col[i] = 1;
            dfs(i);
            if (!flag) {
                int cnt1 = 0, cnt2 = 0;
                for (int j = 0; j < a.size(); j++) {
                    int x = a[j];
                    if (col[x] == 1) cnt1 += 1;
                    else cnt2 += 1;
                }
                ans += max(cnt1, cnt2);
            }
            a.clear();
        }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) 
        vis[i] = false, head[i] = 0;
    cnt = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}