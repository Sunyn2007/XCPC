#include <bits/stdc++.h>
using namespace std;
const int N = 2e7;
int n, lcp[N + 5], ck[26];
string s;
bool bk[26][26], ok = true;
unsigned int dp[1 << 26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s, n = s.size(), s = ' ' + s;
    int l = 1, r = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= r) lcp[i] = min(r - i + 1, lcp[i - l + 1]);
        while (i + lcp[i] <= n && s[1 + lcp[i]] == s[i + lcp[i]]) {
            lcp[i]++;
        }
        if (i + lcp[i] - 1 > r) {
            l = i;
            r = i + lcp[i] - 1;
        }
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
        for (int i = 0; i <= 25; i++)
            for (int j = 0; j <= 25; j++) 
                if (bk[j][i]) ck[i] |= (1 << j);
        for (int i = 1; i < 1 << 26; i++)
            for (int j = 0; j <= 25; j++)
                if (((i >> j) & 1) && (ck[j] & i) == ck[j])
                    dp[i] += dp[i ^ (1 << j)];
        cout << dp[(1 << 26) - 1];
    }
    return 0;
}