#include <bits/stdc++.h>
using namespace std;
const int NM = 4e5;
int t, n, m, q, h[NM + 5], d[NM + 5];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool res[NM + 5];
int hs(int x, int y) {
    return (x - 1) * (m + 1) + 1 + y;
}
void syn() {
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (d[hs(i, j)] == 0)
                q.push(make_pair(i, j));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i <= 3; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || h[hs(xx, yy)] > h[hs(x, y)]) continue;
            if (!res[hs(x, y)]) res[hs(xx, yy)] = true;
            d[hs(xx, yy)] -= 1;
            if (d[hs(xx, yy)] == 0) q.push(make_pair(xx, yy));
        }
    }
    return ;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[hs(i, j)];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            for (int k = 0; k <= 3; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 1 || x > n || y < 1 || y > m) continue;
                if (h[hs(x, y)] > h[hs(i, j)]) d[hs(i, j)] += 1;
            }
    syn();
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int r, c;
        cin >> r >> c;
        if (res[hs(r, c)]) cout << "First" << '\n';
        else cout << "Second" << '\n';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[hs(i, j)] = res[hs(i, j)] = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}