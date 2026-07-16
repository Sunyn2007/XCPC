#include <bits/stdc++.h>
using namespace std;
const int N = 6000;
int t, n, a[N + 5], s[N + 5], flag[N + 5];
vector<pair<int, int> > book[N + 5];
int pl[N + 5][N + 5], pr[N + 5][N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int mn = INT_MAX;
        for (int j = i; j <= n; j++) {
            if (flag[a[j]] == i) break;
            flag[a[j]] = i;
            mn = min(mn, a[j]);
            if (s[j] - s[i - 1] != (mn + mn + j - i) * (j - i + 1) / 2) continue;
            book[j - i + 1].push_back(make_pair(i, mn));
            if (!pl[j - i + 1][mn]) pl[j - i + 1][mn] = i;
            pr[j - i + 1][mn] = i;
        }
    }
    int ans = 0;
    for (int i = n / 2; i >= 1; i--) {
        for (auto it = book[i].begin(); it != book[i].end(); it++) {
            int p = (*it).first, mn = (*it).second;
            if ((mn + i <= n && (pr[i][mn + i] >= p + i || (pl[i][mn + i] && pl[i][mn + i] <= p - i))) ||
                mn - i > 0&& (pr[i][mn - i] >= p + i || (pl[i][mn - i] && pl[i][mn - i] <= p - i))) {
                ans = i;
                break;
            }
        }
        if (ans) break;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        flag[i] = 0, book[i].clear();
        for (int j = 1; j <= n; j++)
            pl[i][j] = 0, pr[i][j] = 0;
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