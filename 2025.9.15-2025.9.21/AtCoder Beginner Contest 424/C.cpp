#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
int n, head[N + 5], cnt, ans;
bool vis[N + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs(int x) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (vis[y]) continue;
        vis[y] = true, ans += 1;
        dfs(y);
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            if (a == 0) add(0, i);
            else add(a, i);
        } 
        else add(a, i), add(b, i);
    }
    dfs(0);
    cout << ans;
    return 0;
}