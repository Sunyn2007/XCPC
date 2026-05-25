#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 1e5;
int t, n, m, a[N + 5], x[N + 5];
priority_queue<int> q1, q2;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2 == 1) q1.push(a[i]);
        else q2.push(a[i]);
    }
    bool flag1 = false, flag2 = false;
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
        if (x[i] % 2 == 1 && !q1.empty() && (q1.top() >= 0 || !flag1)) q1.pop(), flag1 = true;
        if (x[i] % 2 == 0 && !q2.empty() && (q2.top() >= 0 || !flag2)) q2.pop(), flag2 = true;  
    }
    long long ans = 0;
    while (!q1.empty()) ans += q1.top(), q1.pop();
    while (!q2.empty()) ans += q2.top(), q2.pop();
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}