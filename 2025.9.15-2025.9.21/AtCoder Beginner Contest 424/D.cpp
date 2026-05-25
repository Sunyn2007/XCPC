#include <bits/stdc++.h>
using namespace std;
const int H = 7, W = 7, INF = 0x7fffffff;
int t, h, w, dp[H + 5][1 << 7];
char mp[H + 5][W + 5];
string s[H + 5];
bool check(int sta1, int sta2) {
    bool flag = true;
    for (int i = 2; i <= w; i++)
        if (!((sta1 >> (w - i)) & 1) && !((sta1 >> (w - i + 1)) & 1) && !((sta2 >> (w - i)) & 1) && !((sta2 >> (w - i + 1)) & 1))
            flag = false;
    return flag;
}
void solve() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) cin >> s[i];
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            mp[i][j] = s[i][j - 1];
    memset(dp, 0x7f, sizeof(dp));
    for (int sta = 0; sta < (1 << 7); sta++) {
        int res = 0;
        bool flag = true;
        for (int j = 1; j <= w; j++) {
            if (mp[1][j] == '#' && ((sta >> (w - j)) & 1))
                res += 1;
            if (mp[1][j] == '.' && !((sta >> (w - j)) & 1))
                flag = false;
        }
        if(flag) dp[1][sta] = res;
    } 
    for (int i = 2; i <= h; i++) {
        for (int j = 0; j < (1 << 7); j++) {
            int res = 0;
            bool flag = true;
            for (int k = 1; k <= w; k++) {
                if (mp[i][k] == '#' && ((j >> (w - k)) & 1))
                    res += 1;
                if (mp[i][k] == '.' && !((j >> (w - k)) & 1))
                    flag = false;
            }
            if (!flag) continue;
            for (int k = 0; k < (1 << 7); k++) 
                if (check(k, j)) dp[i][j] = min(dp[i][j], dp[i - 1][k] + res);
        }
    }
    int ans = INF;
    for (int sta = 0; sta < (1 << 7); sta++)
        ans = min(ans, dp[h][sta]);
    cout << ans << '\n';
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
****
****
****
****
*/