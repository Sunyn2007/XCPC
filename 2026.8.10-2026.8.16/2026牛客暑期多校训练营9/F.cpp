#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, p[N + 5];
bool a[105][105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) p[i] = i;
    do { 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = false;
        for (int i = 1; i <= n; i++) a[i][p[i]] = true;
        int tot = 0, step = 0;
        while (tot < (n - 1) * n) {
            vector<pair<int, int> > q;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) {
                    if (a[i][j]) continue;
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 1 || x > n || y < 1 || y > n) continue;
                        if (a[x][y]) cnt += 1;
                    }
                    if (cnt >= 2) q.push_back(make_pair(i, j));
                }
            if (!q.empty()) {
                for (auto it : q) a[it.first][it.second] = true;
                tot += q.size(), step += 1;
            }
            else break;
        }
        for (int i = 1; i <= n; i++) cout << p[i] << ' ';
        cout << '\n';
        if (tot < (n - 1) * n) cout << -1 << '\n';
        else cout << step << '\n';
    } while (next_permutation(p + 1, p + n + 1));
    return 0;
}