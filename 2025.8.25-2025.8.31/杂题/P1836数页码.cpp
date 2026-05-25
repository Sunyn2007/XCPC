#include <bits/stdc++.h>
using namespace std;
int x, num[10], cnt;
long long book[10], dp[10], f[10];
void pre() {
    book[0] = 1;
    for (int i = 1; i <= 9; i++)
        book[i] = book[i - 1] * 10;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> x;
    while (x) {
        num[++cnt] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= cnt; i++) {
        f[i] = dp[i] = 0;
        for (int j = 0; j <= 9; j++)
            f[i] = f[i] + j * book[i - 1] + f[i - 1];
        for (int j = 0; j <= num[i]; j++) {
            if (j == num[i]) dp[i] = dp[i] + j * (x + 1) + dp[i - 1];
            else dp[i] = dp[i] + j * book[i - 1] + f[i - 1];
        }
        x += num[i] * book[i - 1];
    }
    cout << dp[cnt];
    return 0;
}