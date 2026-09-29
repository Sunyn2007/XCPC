#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
struct Pos {
    int xp;
    int yp;
    int di;
};
int n;
int mg[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> mg[i][j];
            vis[i][j] = false;
        }
    if (mg[0][0] == 1 || mg[n - 1][n - 1] == 1) {
        cout << "no path" << '\n';
        return;
    }
    stack<Pos> path;
    path.push({0, 0, 0});
    vis[0][0] = true;
    bool found = false;
    while (!path.empty()) {
        Pos &cur = path.top();
        if (cur.xp == n - 1 && cur.yp == n - 1) {
            found = true;
            break;
        }
        int nx = -1, ny = -1;
        while (cur.di < 4) {
            int d = cur.di++;
            int tx = cur.xp + dx[d], ty = cur.yp + dy[d];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
            if (mg[tx][ty] == 1 || vis[tx][ty]) continue;
            nx = tx;
            ny = ty;
            break;
        }
        if (nx == -1) {
            path.pop();
            continue;
        }
        vis[nx][ny] = true;
        path.push({nx, ny, 0});
    }
    if (!found) {
        cout << "no path" << '\n';
        return;
    }
    stack<Pos> path1;
    while (!path.empty()) {
        path1.push(path.top());
        path.pop();
    }
    int i = 0;
    while (!path1.empty()) {
        Pos cur = path1.top();
        path1.pop();
        if (++i % 4 == 0) cout << '[' << cur.xp << ',' << cur.yp << ']' << "--" << '\n';
        else cout << '[' << cur.xp << ',' << cur.yp << ']' << "--";
    }
    cout << "END" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
