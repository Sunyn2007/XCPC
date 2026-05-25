#include <bits/stdc++.h>
using namespace std;
const int N = 18, MOD = 998244353;
int n, l, sum[30], ans, c[30][30];
string s[N + 5];
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }   
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int sta = 0; sta < (1 << n); sta++) {
        int tot = 0, cnt = 0;
        memset(sum, 0, sizeof(sum));
        for (int j = 1; j <= n; j++)
            if ((sta >> (j - 1)) & 1) {
                tot += 1;
                for (int k = 0; k < s[j].size(); k++) 
                    sum[s[j][k] - 'a'] += 1;
            }
        if (tot == 0) continue;
        for (int j = 0; j < 26; j++)
            if (sum[j] == tot) cnt += 1;
        if (tot % 2 == 1) ans = (ans + qpow(cnt, l)) % MOD; 
        else ans = (ans - qpow(cnt, l)) % MOD;
    }
    cout << (ans + MOD) % MOD;
    return 0;
}