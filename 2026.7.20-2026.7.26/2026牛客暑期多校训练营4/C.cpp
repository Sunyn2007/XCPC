#include <bits/stdc++.h>
using namespace std;
const int N = 2e4, M = 20;
int n, m, d[N + 5][M + 5];
long long sum[1 << M][M + 5], dp[1 << M];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> d[i][j];
        cin >> s, s = ' ' + s;
        int sta = 0;
        for (int j = 1; j <= m; j++)
            if (s[j] == 'A') sta |= (1 << j - 1);
        for (int j = 1; j <= m; j++)
            sum[sta][j] += d[i][j];
    }
    for (int i = 1; i <= m; i++)
        for (int sta = (1 << m) - 1; sta >= 0; sta--)
            if ((sta & (1 << i - 1)) == 0) 
                for (int j = 1; j <= m; j++) sum[sta][j] += sum[sta | (1 << i - 1)][j];
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    for (int sta = 1; sta < (1 << m); sta++)
        for (int i = 1; i <= m; i++)
            if ((sta >> i - 1) & 1)
                dp[sta] = min(dp[sta], dp[sta ^ (1 << i - 1)] + sum[sta ^ (1 << i - 1)][i]);
    cout << dp[(1 << m) - 1];
    return 0;
}