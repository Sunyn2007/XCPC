#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int t, n, m, v[N + 5];
vector<int> a[N + 5];
priority_queue<int> q;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    int ans = m;
    for (int i = n; i >= 1; i--) {
        vector<int> tmp;
        for (auto x : a[i]) q.push(x);
        long long sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += q.top(), tmp.push_back(q.top());
            q.pop();
            if (sum >= v[i]) ans = min(ans, j);
        }
        for (auto x : tmp) q.push(x);
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) a[i].clear();
    while (!q.empty()) q.pop();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}