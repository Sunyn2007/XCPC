#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5];
bool check(int cnt) {
    priority_queue<int> q;
    int tk = k + cnt;
    for (int i = 1; i <= n; i++) q.push(a[i]);
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        if ()
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = n, res;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = r = mid - 1;
        else l = mid + 1;
    }
    cout << 3 * res + (n - res) << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}