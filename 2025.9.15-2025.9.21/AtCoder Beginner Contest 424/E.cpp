#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, k, x;
double a[N + 5];
priority_queue< pair<double, int> > q;
void solve() {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q.push(make_pair(a[i], 1));
    }   
    while (k) {
        double len = q.top().first;
        int cnt = q.top().second;
        q.pop();
        if (k - cnt >= 0) {
            k -= cnt;
            q.push(make_pair(len / 2.0, cnt << 1));
        }
        else {
            q.push(make_pair(len / 2.0, k << 1));
            q.push(make_pair(len, cnt - k));
            break;
        }
    }
    while(x) {
        double len = q.top().first;
        int cnt = q.top().second;
        q.pop();
        if (x - cnt > 0) x -= cnt;
        else {
            cout << fixed << setprecision(10) << len << '\n';
            break;
        }
    }
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