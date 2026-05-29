#include <bits/stdc++.h>
using namespace std;
const int N = 500, MOD = 1e9 + 7;
int n, m, dp[N + 5][N + 5][4], cnt[N + 5];
char s[N + 5];
bool check(int i, int j) {
    if (s[i] == '(' && s[j] == ')') return true;
    if (s[i] == '(' && s[j] == '?') return true;
    if (s[i] == '?' && s[j] == ')') return true;
    if (s[i] == '?' && s[j] == '?') return true;
    return false;
}
int add(int x, int y) {
    int res = x + y;
    if (res < 0) res += MOD;
    if (res >= MOD) res -= MOD;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> (s + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + (s[i] == '(' || s[i] == ')');
        if (i > 1 && check(i - 1, i)) dp[i - 1][i][3] = 1;
    }
    for (int l = 3; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            if (check(i, j)) {
                if ((j - 1 - i) <= m && cnt[j - 1] - cnt[i] == 0) dp[i][j][3] = add(dp[i][j][3], 1);
                dp[i][j][3] = add(dp[i][j][3], dp[i + 1][j - 1][0]);
                dp[i][j][3] = add(dp[i][j][3], dp[i + 1][j - 1][3]);
                dp[i][j][3] = add(dp[i][j][3], dp[i + 1][j - 1][1]);
                dp[i][j][3] = add(dp[i][j][3], dp[i + 1][j - 1][2]);
                for (int k = i; k < j; k++) {
                    dp[i][j][0] = add(dp[i][j][0], 1ll * dp[i][k][3] * dp[k + 1][j][0] % MOD);
                    dp[i][j][0] = add(dp[i][j][0], 1ll * dp[i][k][3] * dp[k + 1][j][2] % MOD);
                    dp[i][j][0] = add(dp[i][j][0], 1ll * dp[i][k][3] * dp[k + 1][j][3] % MOD);
                }
            }
            if (s[j] == '*' || s[j] == '?')
                for (int k = max(i, j - m); k < j; k++)
                    if (cnt[j] - cnt[k] == 0) {
                        dp[i][j][1] = add(dp[i][j][1], dp[i][k][0]);
                        dp[i][j][1] = add(dp[i][j][1], dp[i][k][3]);
                    }
            if (s[i] == '*' || s[i] == '?')
                for (int k = min(j, i + m); k > i; k--)
                    if (cnt[k - 1] - cnt[i - 1] == 0) {
                        dp[i][j][2] = add(dp[i][j][2], dp[k][j][0]);
                        dp[i][j][2] = add(dp[i][j][2], dp[k][j][3]);
                    }
        }
    cout << add(dp[1][n][0], dp[1][n][3]);
    return 0;
}