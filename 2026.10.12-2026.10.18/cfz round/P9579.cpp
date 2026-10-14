#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n, dp[N + 5];
map<int, int> bk;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        mx = max({mx, a, b});
        if (a > b) {
            if (bk.find(a) == bk.end()) bk[a] = b;
            else bk[a] = min(bk[a], b);
        }
    }
    vector<pair<int, int> > s;
    for (auto [x, y] : bk)
        s.push_back(make_pair(x, y));
    reverse(s.begin(), s.end());
    int mn = INT_MAX, now = 0;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i].first, y = s[i].second;
        if (y >= mn) continue;
        now += 1;
        dp[now] = min(mx - y, dp[now - 1] + (min(mn, x) - y) * 2);
        mn = y;
    }
    cout << mx + dp[now];
    return 0;
}