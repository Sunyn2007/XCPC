#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, M = 1e6;
int t, n, m, p[N + 5], l[M + 5], r[M + 5], deg[N + 5];
vector<int> to[N + 5];
vector<int> id[M + 5];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; j++) {
            int x;
            cin >> x;
            id[i].push_back(x);
        } 
        for (int j = 1; j < id[i].size(); j++) 
            to[id[i][j]].push_back(id[i][j - 1]), deg[id[i][j - 1]] += 1;
    }
    int now = n;
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!deg[i]) q.push(i);
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        p[x] = now--;
        for (auto y : to[x]) {
            deg[y] -= 1;
            if (deg[y] == 0) q.push(y);
        }
    }
    if (now) cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; i++) cout << p[i] << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) to[i].clear(), deg[i] = 0;
    for (int i = 1; i <= m; i++) id[i].clear();
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}