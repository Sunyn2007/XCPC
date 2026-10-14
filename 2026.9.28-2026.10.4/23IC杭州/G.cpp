#include <bits/stdc++.h>
using namespace std;
const int N = 3000, M = 3000, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, INF = 0x3f3f3f3f;
int n, m, k, a[N + 5][M + 5];
unsigned long long dis[N + 5][M + 5], ans;
bool vis[N + 5][M + 5];
string s[N + 5];
struct node {
    int x, y, d;
    bool operator<(const node &b) const {
        return d > b.d;
    }
};
priority_queue<node> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dis[i][j] = INF;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = i;
        if (i == 1) {
            dis[x][y] = 0;
            q.push({x, y, 0});
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) 
            if (s[i][j] == '#') a[i][j + 1] = -1;
    }
    while (!q.empty()) {
        node u = q.top();
        q.pop();
        if (vis[u.x][u.y]) continue;
        vis[u.x][u.y] = true;
        for (int i = 0; i < 4; i++) {
            node v;
            v.x = u.x + dx[i], v.y = u.y + dy[i];
            if (v.x < 1 || v.x > n || v.y < 1 || v.y > m || a[v.x][v.y] == -1) continue;
            if (a[v.x][v.y]) v.d = max(u.d + 1, k - a[v.x][v.y] + 1);
            else v.d = u.d + 1;
            if (v.d < dis[v.x][v.y]) {
                dis[v.x][v.y] = v.d;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dis[i][j] != INF) ans += dis[i][j] * dis[i][j];
            //cout << dis[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << ans;
    return 0;
}