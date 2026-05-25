#include <bits/stdc++.h>
using namespace std;
const int N = 3e5, M = 3e5;
struct edge{
    int to, nxt;
}e[M + 5];
int cnt, head[N + 5];
int n, m, tot;
bool book[N + 5], blk[N + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    int ans = 1;
    book[1] = true;
    for (int i = 1; i <= n; i++) {
        if (!book[i]) blk[i] = true, tot += 1;
        else {
            ans -= 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int j = head[x]; j; j = e[j].nxt) {
                    int y = e[j].to;
                    if (!book[y]) {
                        book[y] = true;
                        if (blk[y]) blk[y] = false, tot -= 1, q.push(y);
                        else ans += 1;
                    }
                }
            }
        }
        if (tot) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}