#include <bits/stdc++.h>
using namespace std;
const long long INF = LONG_LONG_MIN;
const int N = 16;
int n, a[N + 5][N + 5];
long long dp[(1 << N) + 5], val[(1 << N) + 5];
int bct(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt += 1;
        x >>= 1;
    }
    return cnt;
}
long long dfs(int mask) {
    if (dp[mask] != INF) return dp[mask];
    for (int i = mask; i; i = (i - 1) & mask)
        dp[mask] = max(dp[mask], dfs(mask ^ i) + val[i]);
    return dp[mask];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    for (int i = 0; i < (1 << N); i++) {
        dp[i] = INF;
        vector<int> tmp;
        long long sum = 0;
        for (int j = 1; j <= n; j++)
            if ((i >> j - 1) & 1) tmp.push_back(j);
        for (int j = 0; j < tmp.size(); j++)
            for (int k = j + 1; k < tmp.size(); k++)
                sum += a[tmp[j]][tmp[k]];
        val[i] = sum;
    }
    dp[0] = 0;
    cout << dfs((1 << n) - 1);
    return 0;
}