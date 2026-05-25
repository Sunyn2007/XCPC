#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, g[N + 5];
priority_queue<int> q;
void solve () {
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> g[i], q.push(g[i]);
    while (q.top() != 0) {
        int a, b;
        a = q.top(), q.pop();
        b = q.top(), q.pop();
        ans += a;
        q.push(0);
    }
    cout << ans << '\n';
    while(!q.empty()) q.pop();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}