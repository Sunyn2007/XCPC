#include <bits/stdc++.h>
using namespace std;
const int N = 1000, M = 1000;
int n, m, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int fa[N * M + 5], siz[N * M + 5];
string s[N + 5];
int h(int x, int y) {
    return (x - 1) * m + y;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) fa[x] = y, siz[y] += siz[x];
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] = ' ' + s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fa[h(i, j)] = h(i, j), siz[h(i, j)] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            if (s[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || x > n || y < 1 || y > m) continue;
                    if (s[x][y] == '.') merge(h(i, j), h(x, y));
                }
            }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '*') {
                int res = 1;
                vector<int> a;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || x > n || y < 1 || y > m) continue;
                    if (s[x][y] == '*') continue;
                    bool flag = true;
                    for (int o = 0; o < a.size(); o++)
                        if (find(h(x, y)) == find(a[o])) flag = false;
                    if (flag) res += siz[find(h(x, y))];
                    a.push_back(h(x, y));
                }
                cout << res % 10;
            }
            else cout << s[i][j];
        }
        cout << '\n';
    }
    return 0;
}