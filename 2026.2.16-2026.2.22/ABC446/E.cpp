#include <bits/stdc++.h>
using namespace std;
const int M = 1000;
int m, a, b, ans;
vector<int> book[M + 5];
map<pair<int, int>, bool> vis;
queue<pair<int, int> > q;
void bfs() {
    while (!q.empty()) {
        int s = q.front().second, y = q.front().first, x, tmp = ((s - a * y) % m + m) % m;
        q.pop();
        for (int i = 0; i < book[tmp].size(); i++) {
            x = book[tmp][i];
            if (!vis[make_pair(x, y)]) {
                q.push(make_pair(x, y));
                vis[make_pair(x, y)] = true;
            }
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> a >> b;
    for (int i = 0; i < m; i++)
        book[b * i % m].push_back(i);
    q.push(make_pair(0, 0)), vis[make_pair(0, 0)] = true;
    for (int i = 1; i < m; i++) {
        q.push(make_pair(i, 0)), vis[make_pair(i, 0)] = true;
        q.push(make_pair(0, i)), vis[make_pair(0, i)] = true;
    }
    bfs();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (!vis[make_pair(i, j)]) ans += 1;
    cout << ans;
    return 0;
}