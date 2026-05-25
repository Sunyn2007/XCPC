#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int h, w, ans, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
string s[N + 5];
map<pair<int, int>, int> vis;
queue< pair<int, int> > q;
vector< pair<int, int> > st[N + 5];
void bfs() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            if (s[i][j] == '#') {
                q.push(make_pair(i, j));
                vis[make_pair(i, j)] = 1;
                st[1].push_back(make_pair(i, j));
                ans += 1;
            }
    }
    int now = 0;
    while (!q.empty()) {
        int x1 = q.front().first, y1 = q.front().second;
        q.pop();
        if (vis[make_pair(x1, y1)] == now + 1) {
            now += 1;
            for (int i = 0; i < st[now].size(); i++) 
                s[st[now][i].first][st[now][i].second] = '#';
        }
        for (int i = 0; i <= 3; i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i], cnt = 0;
            if (x2 < 1 || x2 > h || y2 < 1 || y2 > w) continue;
            if (vis[make_pair(x2, y2)]) continue;
            if (x2 > 1 && s[x2 - 1][y2] == '#') cnt += 1;
            if (x2 < h && s[x2 + 1][y2] == '#') cnt += 1;
            if (y2 > 1 && s[x2][y2 - 1] == '#') cnt += 1;
            if (y2 < w && s[x2][y2 + 1] == '#') cnt += 1;
            if (cnt == 1) {
                vis[make_pair(x2, y2)] = now + 1;
                q.push(make_pair(x2, y2));
                st[now + 1].push_back(make_pair(x2, y2));
                ans += 1;
            } 
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        cin >> s[i], s[i] = ' ' + s[i];
    bfs();
    cout << ans << '\n';
    /*
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            cout << vis[make_pair(i, j)] << ' ';
        cout << '\n';
    }
    */
    return 0;
}