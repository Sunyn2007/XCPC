#include <bits/stdc++.h>
using namespace std;
const int N = 3e5, MOD = 998244353;
int t, n, p[N + 5], sr[N + 5], sl[N + 5];
string s;
void init() {
    p[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = (p[i - 1] << 1) % MOD;
}
void solve() {
    cin >> n >> s, s = ' ' + s;
    int lst = 0, mul = 1, cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        sl[i] = sl[i - 1], sr[i] = sr[i - 1];
        if (s[i] == '(') {
            cnt += 1, sl[i] += 1;
            ans = (ans + p[i - 1]) % MOD;
        }
        else {
            cnt -= 1, sr[i] += 1;
            ans = (ans + 1ll * mul * p[i - lst - 1] % MOD) % MOD;
        }
        if (cnt <= 1) {
            int tmp = p[sr[i] - sr[lst]];
            for (int j = lst + 1; j <= i; j++)
                if (s[j] == '(')
                    tmp = (tmp + 1ll * p[j - lst - 1] * (p[sr[i] - sr[j]] - 1) % MOD) % MOD;
            mul = 1ll * mul * tmp % MOD;
            lst = i;
        }
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) solve();
    return 0;
}