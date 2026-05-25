#include <bits/stdc++.h>
using namespace std;
const int N = 5e4, M = 1e5;
int t, n, m, l[N + 5];
vector<int> book[M + 5];
bool vis[N + 5];
void clear() {
    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= m; i++) book[i].clear();
    return ;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        for (int j = 1; j <= l[i]; j++) {
            int x;
            cin >> x;
            book[x].push_back(i);
        }
    }
    bool flag = true;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (book[i].size() == 0) flag = false;
        if (book[i].size() == 1) {
            if (!vis[book[i][0]]) cnt += 1;
            vis[book[i][0]] = true;
        }
    }
    if (!flag) cout << "No" << '\n';
    else {
        if (cnt <= n - 2) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}