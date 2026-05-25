#include <bits/stdc++.h>
using namespace std;
int t, n;
string s1, s2;
vector<pair<int, int> > ans[2];
void op(int l, int r, string &s, int tag) {
    for (int i = l; i <= r; i++) {
        if (s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
    ans[tag].push_back(make_pair(l, r));
    return ;
} 
void syn(int tag, string s) {
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0') {
            flag = false;
            break;
        }
    if (flag) return ;
    int l = 0, r = 0, now;
    for (int i = 2; i <= n; i++)
        if (s[i] == s[i - 1]) {
            l = i - 1, r = i, now = s[i] - '0';
            break;
        }
    if (!l) op(1, 3, s, tag), l = 3, r = 4, now = s[4] - '0';
    while (true) {
        while (l > 1 && s[l - 1] == s[l]) l -= 1;
        while (r < n && s[r + 1] == s[r]) r += 1;
        if (l == 1 && r == n) {
            if (now == 0) op(l, r, s, tag);
            break;
        }
        op(l, r, s, tag), now = !now;
    }
    return ;
}
void solve() {
    cin >> n >> s1 >> s2;
    s1 = ' ' + s1, s2 = ' ' + s2;
    syn(0, s1), syn(1, s2);
    cout << ans[0].size() + ans[1].size() << '\n';
    for (int i = 0; i < ans[0].size(); i++)    
        cout << ans[0][i].first << ' ' << ans[0][i].second << '\n';
    for (int i = ans[1].size() - 1; i >= 0; i--)    
        cout << ans[1][i].first << ' ' << ans[1][i].second << '\n';
    ans[0].clear(), ans[1].clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>  t;
    while (t--) solve();
    return 0;
}