#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], b[N + 5];
priority_queue< pair<int, int> > q;
void solve() {
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = n; i >= 1; i--) {
        long long sum = 0;
        while(!q.empty()) {
            if (-q.top().first <= a[i]) {
                sum += q.top().second;
                q.pop();
            }
            else break;
        }
        ans += i * sum;
        if (a[i] != b[i]) q.push(make_pair(-max(a[i], b[i]), n - i + 1));
        else ans += (long long)i * (n - i + 1);
    }
    cout << ans << '\n';
    while (!q.empty()) q.pop();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
5 8 9 4 5
*/