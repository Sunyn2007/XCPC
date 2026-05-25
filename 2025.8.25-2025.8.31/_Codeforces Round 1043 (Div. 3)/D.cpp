#include <bits/stdc++.h>
using namespace std;
int t, num[20];
long long k, book[20], dp[20], f[20];
void pre() {
    book[0] = 1;
    for (int i = 1; i <= 18; i++)
        book[i] = book[i - 1] * 10;
    return ;
}
void solve() {
    cin >> k;
    int now = 1, cnt = 0, add = 0;
    while (true) {
        if (k > 9 * book[now - 1] * now) {
            k -= 9 * book[now - 1] * now;
            now += 1;
        }
        else {
            long long tmp = k / now, x = book[now - 1] + tmp - 1;
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
            k -= tmp * now, x += 1;
            for (int i = 1; i <= now; i++) {
                num[i] = x % 10;
                x /= 10;
            }
            for (int i = now; i >= 1 && k >= 1; i--, k--) 
                add += num[i];
            break;
        }
    }
    cout << dp[cnt] + add << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    while (t--) solve();
    return 0;
}