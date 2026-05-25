#include <bits/stdc++.h>
using namespace std;
const int A = 1e6;
int a, b;
double p, q, dp[A + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> p >> q;
    p /= 100.0, q /= 100.0;
    for (int i = b; i <= a; i++) {
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], (dp[i - b] + 2.0) * p + (dp[i - b] + 1.0) * (1.0 - p));
        if (b == 1) dp[i] = max(dp[i], dp[i - b] + 1.0 / (1.0 - q));
        else dp[i] = max(dp[i], (dp[i - b + 1] + 1.0) * q + (dp[i - b] + 1.0) * (1.0 - q));
    }
    cout << fixed << setprecision(10) << dp[a];
    return 0;
}


/*
dp[i] = (dp[i - b] + 2) * p + (dp[i - b] + 1) * (1 - p);
dp[i] = (dp[i - b + 1] + 1) * q + (dp[i - b] + 1) * (1 - q);
x = (x + 1) * q + (y + 1) * (1 - q)
x = x * q + q + y - y * q + 1 - q
x * (1 - q) = y * (1 - q) + 1
x = y + 1 / (1 - q)
*/