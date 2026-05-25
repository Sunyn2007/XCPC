#include <bits/stdc++.h>
using namespace std;
const int N = 22, MOD = 998244353, S = 5e6;
int n, dp[(1 << N) + 5], sta[(1 << N) + 5], trie[S + 5][26], num, book[S + 5], stk[N + 5], top;
string s, tmp;
bool vis[(1 << N) + 5];
int insert(string s) {
    int now = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (!trie[now][s[i] - 'a']) 
            flag = true, trie[now][s[i] - 'a'] = ++num;
        now = trie[now][s[i] - 'a'];
    }
    return now;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> s, s = ' ' + s;
    for (int i = 0; i < (1 << n); i++) {
        tmp.clear();
        for (int j = 1; j <= n; j++)
            if ((i >> n - j) & 1) tmp += s[j];
        int hs = insert(tmp);
        if (!book[hs]) book[hs] = i;
        sta[i] = book[hs];
    }
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 1; j <= n; j++)
            if ((i >> n - j) & 1) {
                int pre = sta[i ^ (1 << n - j)];
                if (!vis[pre]) {
                    dp[i] += dp[pre];
                    if (dp[i] >= MOD) dp[i] -= MOD;
                    vis[pre] = true, stk[++top] = pre;
                }
            }
        while (top) vis[stk[top--]] = false;
    }
    cout << dp[(1 << n) - 1];
    return 0;
}