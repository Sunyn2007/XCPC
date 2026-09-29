#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 1e5;
int t, n, m, head[N + 5], cnt;
vector<int> ans;
bool dam[N + 5], fl;
struct edge {
    int to, nxt;
}e[N + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs(int x, bool tag) {
    if (dam[x]) {
        if (fl && !tag) fl = false;
        else ans.push_back(x);
    }
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        dfs(y, tag | dam[x]);
    }
    
}
void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;
        add(fa, i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        dam[x] = true;
    }
    fl = true;
    dfs(1, false);
    cout << ans.size() << ' ';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
    ans.clear();
    for (int i = 0; i <= n; i++) head[i] = dam[i] = 0;
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