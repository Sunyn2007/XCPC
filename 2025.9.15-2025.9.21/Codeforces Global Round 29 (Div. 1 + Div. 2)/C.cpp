#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n;
bool dp[N + 5][4];
string s;
void solve() {
    cin >> n >> s;
    s = '0' + s + '0';
    dp[0][0] = dp[0][1] = true;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            dp[i][2] = dp[i - 1][1] | dp[i - 1][2] | dp[i - 1][3];
            dp[i][3] = dp[i - 1][0] | dp[i - 1][2] | dp[i - 1][3];
        }
        else {
            dp[i][0] = dp[i - 1][0] | dp[i - 1][2];
            dp[i][1] = dp[i - 1][3]; 
        }
    }
    if (dp[n][0] || dp[n][2] || dp[n][3]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}