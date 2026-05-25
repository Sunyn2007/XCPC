#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, m, h[N + 5], a[N + 5], id[N + 5];
vector<pair<int, int> > ans;
map<int, int> book;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], book[a[i]] = i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) 
        h[i] = a[i], id[i] = book[a[i]];
    if (m * 2 > n)
        cout << -1 << '\n';
    else if (m) {
        for (int i = 1; i <= n - m * 2; i++)
            ans.push_back(make_pair(id[i + 1], id[i]));
        for (int i = n; i >= n - m + 1; i--)
            ans.push_back(make_pair(id[i], id[i - m]));
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    else {
        int now = n - 2;
        while (now >= 1) {
            if (h[n] <= a[now]) break;
            h[n] -= a[now];
            ans.push_back(make_pair(id[now], id[n]));
            now -= 1;
        }
        for (int i = 1; i < now; i++)
            ans.push_back(make_pair(id[i + 1], id[i]));
        if (now) ans.push_back(make_pair(id[n - 1], id[now]));
        ans.push_back(make_pair(id[n], id[n - 1]));
        if (h[n] <= a[n - 1]) {
            cout << ans.size() << '\n';
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
        else cout << -1 << '\n';
    }
    ans.clear(), book.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}