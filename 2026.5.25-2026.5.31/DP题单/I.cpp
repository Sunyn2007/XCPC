#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int n, a[N + 5];
long long dp[N + 5][4];
char s[N + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= 3; j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'h') {
            dp[i][0] = dp[i - 1][0] + a[i];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3]; 
        }
        else if (s[i] == 'a') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + a[i];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][3] = dp[i - 1][3];
        }
        else if (s[i] == 'r') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2] + a[i];
            dp[i][3] = min(dp[i - 1][2], dp[i - 1][3]);
        }
        else if (s[i] == 'd') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3] + a[i]; 
        }
        else {
            for (int j = 0; j <= 3; j++)
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
    return 0;
}