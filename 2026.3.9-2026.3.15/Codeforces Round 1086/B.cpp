#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int t, n, k, p, m, a[N + 5], v;
queue<int> q2;
priority_queue<int> q1;
void solve() {
    cin >> n >> k >> p >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    v = a[p], a[p] = 0;
    for (int i = 1; i <= k; i++)
        q1.push(-a[i]);
    for (int i = k + 1; i <= n; i++)
        q2.push(a[i]);
    int ans = 0;
    while (m) {
        int x = -q1.top();
        q1.pop();
        if (x == 0) {
            if (m >= v) m -= v, ans += 1;
            else break;
        }
        else {
            if (m >= x) m -= x;
            else break;
        }
        q2.push(x);
        q1.push(-q2.front());
        q2.pop();
    }
    cout << ans << '\n';
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}