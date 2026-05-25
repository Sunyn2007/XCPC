#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n;
string s1, s2;
vector<pair<int, int> > ans;
bool dp[N + 5][N + 5];
void flip(int l, int r) {
    ans.push_back(make_pair(l, r));
    for (int i = l; i <= r; i++) {
        if (s1[i] == '1') s1[i] = '0';
        else s1[i] = '1';
    }
    return ;
}

void solve() {
    cin >> n >> s1 >> s2;
    s1 = ' ' + s1, s2 = ' ' + s2;
    for (int i = 1; i <= n - 2; i++)
        if (s1[i] != s2[i]) {
            if (s1[i + 1] == s1[i]) flip(i, i + 1);
            else {
                if (s1[i + 2] == s1[i + 1]) {
                    flip(i + 1, i + 2);
                    flip(i, i + 2);
                }
                else flip(i, i + 2);
            }
        }
    bool ok = true;
    if (s1[n - 1] != s2[n - 1] || s1[n] != s2[n]) {
        if (s1[n - 1] == s1[n] && s2[n - 1] == s2[n]) flip(n - 1, n);
        else {
            if (s1[n - 1] == s2[n - 1]) {

            }
            else if (s1[n] == s2[n]) {

            }
            else {

            }
        }
    }
    if (!ok) cout << -1 << '\n';
    else {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    ans.clear();
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

100

*/