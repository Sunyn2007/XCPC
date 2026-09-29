#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int t, n, m;
string s[7];
void print(int x, int y) {
    cout << x << ' ' << y << '\n';
    return ;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> s[i], s[i] = ' ' + s[i];
    int tot = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '.' || s[i][j] == '?') tot += 1;
    cout << tot << '\n';
    while (cnt < tot) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i][j] == 'O') {
                    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
                    for (int k = 0; k <= 7; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 1 || x > n || y < 1 || y > m) continue;
                        if (s[x][y] == '#' || s[x][y] == '*') cnt1 += 1;
                        if (s[x][y] == '*') cnt2 += 1;
                        if (s[x][y] == '#' || s[x][y] == '.' || s[x][y] == '?') cnt3 += 1;
                    }
                    if (cnt1 == cnt2 || cnt1 == cnt2 + cnt3) {
                        for (int k = 0; k <= 7; k++) {
                            int x = i + dx[k], y = j + dy[k];
                            if (x < 1 || x > n || y < 1 || y > m) continue;
                            if (s[x][y] == '#') s[x][y] = '*';
                            if (s[x][y] == '.') print(x, y), cnt += 1, s[x][y] = 'O';
                            if (s[x][y] == '?') print(x, y), cnt += 1, s[x][y] = '.';
                        }
                    }
                }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}