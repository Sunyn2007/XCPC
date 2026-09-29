#include <bits/stdc++.h>
using namespace std;
const int N = 2e7;
struct syn {
    int id, x, y;
}t1[N + 5], t2[N + 5];
int n, sa[N + 5], rk[N + 5], h[N + 5], cnt[N + 5], len, v, num;
int lcp[N + 5];
string s;
bool bk[26][26], ok = true;
unsigned int dp[1 << 26];
int bt(int x) {
    int res = 1;
    while (!(x & 1)) res += 1, x >>= 1;
    return res;
}
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    cin >> s, n = s.size(), s = ' ' + s;
    for (int i = 1; i <= n; i++)
        rk[i] = s[i], v = max(v, (int)s[i]);
    for (len = 1; len <= n; len <<= 1) {
        for (int i = 1; i <= n; i++)
            t1[i].id = i, t1[i].x = rk[i], t1[i].y = (i + len > n ? 0 : rk[i + len]);
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t1[i].y] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t2[cnt[t1[i].y]--] = t1[i];
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t1[i].x] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t1[cnt[t2[i].x]--] = t2[i];
        num = 0;
        for (int i = 1; i <= n; i++) {
            if (i == 1 || t1[i].x != t1[i - 1].x || t1[i].y != t1[i - 1].y) num += 1;
            rk[t1[i].id] = num;
        }
        if (num == n) break;
        else v = num;
    }
    for (int i = 1; i <= n; i++) sa[rk[i]] = i;
    len = 0;
    for (int i = 1; i <= n; i++) {
        if (rk[i] == 1) len = 0;
        else {
            if (len) len -= 1;
            int j = sa[rk[i] - 1];
            while (i + len <= n && j + len <= n && s[i + len] == s[j + len]) len += 1;
        }
        h[rk[i]] = len;
    }
    int tmp = INT_MAX;
    for (int i = rk[1]; i >= 2; i--) {
        tmp = min(tmp, h[i]);
        lcp[sa[i - 1]] = tmp;
    }
    tmp = INT_MAX;
    for (int i = rk[1] + 1; i <= n; i++) {
        tmp = min(tmp, h[i]);
        lcp[sa[i]] = tmp;
    }
    for (int i = 2; i <= n; i++) {
        if (lcp[i] >= n - i + 1 || s[1 + lcp[i]] == s[i + lcp[i]]) {
            ok = false;
            break;
        }
        bk[s[1 + lcp[i]] - 'a'][s[i + lcp[i]] - 'a'] = true;
    }
    if (!ok) cout << 0;
    else {
        dp[0] = 1;
        for (int i = 1; i < 1 << 26; i++) {
            for (int j = 0; j <= 25; j++)
                if ((i >> j) & 1) {
                    bool fl = true;
                    for (int k = 0; k <= 25; k++)
                        if (k != j && ((i >> k) & 1) && bk[j][k]) fl = false;
                    if (fl) dp[i] += dp[i ^ (1 << j)];
                }
        }
        cout << dp[(1 << 26) - 1];
    }
    return 0;
}