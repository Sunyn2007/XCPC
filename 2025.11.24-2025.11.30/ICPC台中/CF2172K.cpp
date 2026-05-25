#include <bits/stdc++.h>
using namespace std;
const int N = 1e3, M = 1e3, Q = 1e5, V = 1e6;
int n, m, q, ans[Q + 5], book[V + 5];
string s[N + 5];
void calc(int x, int y, int dx, int dy) {
    int sx = x, sy = y;
    int tot = 0, tmp = 1, num = 0;
    bool flag = true;
    while (x >= 1 && x <= n && y >= 1 && y <= m) {
        if (s[x][y] >= '0' && s[x][y] <= '9') {
            flag = false;
            num = num * 10 + (s[x][y] - '0');
            int res = tot + tmp * num;
            if (res > V) break;
            if (book[res] && (sx != x || sy != y)) ans[book[res]] += 1;
        }
        else {
            if (flag) break;
            flag = true;
            if (s[x][y] == '+') tot += tmp * num, tmp = 1;
            if (s[x][y] == '*') tmp *= num;
            num = 0;
        }
        x += dx, y += dy;
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] = ' ' + s[i];
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        book[x] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j] >= '0' && s[i][j] <= '9') {
                if (book[s[i][j] - '0']) ans[book[s[i][j] - '0']] += 1;
                calc(i, j, 1, 0), calc(i, j, 0, 1), calc(i, j, -1, 0), calc(i, j, 0, -1);
                calc(i, j, 1, 1), calc(i, j, 1, -1), calc(i, j, -1, -1), calc(i, j, -1, 1);
            }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}