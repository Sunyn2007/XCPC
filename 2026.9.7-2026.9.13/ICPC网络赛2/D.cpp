#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19, MOD = 998244353;
int n, q, v[N + 5], ans = 1;
bool ok = true;
vector<int> s[N + 5];
void dfs1(int x, int dep) {
    if (dep == n) {
        if (v[x]) s[x].push_back(v[x]);
        return ;
    }
    dfs1(x << 1, dep + 1), dfs1(x << 1 | 1, dep + 1);
    for (auto y : s[x << 1]) s[x].push_back(y);
    for (auto y : s[x << 1 | 1]) s[x].push_back(y);
    if (v[x]) s[x].push_back(v[x]);
    if (v[x << 1] && v[x << 1 | 1]) {
        if (v[x] && max(v[x << 1], v[x << 1 | 1]) != v[x]) ok = false;
        else v[x] = max(v[x << 1], v[x << 1 | 1]);
    }
    return ;
}
void dfs2(int x, int dep) {
    if (dep == n) return ;
    int len = 1 << n - dep;
    if (v[x << 1] && v[x << 1 | 1]) {
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    v[1] = n;
    for (int i = 1; i <= n; i++) {
        int u, x;
        cin >> u >> x;
        if (v[u]) {
            cout << 0 << '\n';
            return ;
        }
        v[u] = x;
    }
    dfs1(1, 0);
    if (!ok) {
        cout << 0 << '\n';
        return ;
    }
    dfs2(1, 0);
    cout << ans << '\n';
    return 0;
}