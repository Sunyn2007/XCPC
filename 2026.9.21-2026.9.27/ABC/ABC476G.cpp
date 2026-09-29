#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int t;
long long ql, qr, dp[64][2][64], ans;
long long dfs(int now, int fl, int cnt, long long ub) {
    if (cnt < 0) return 0;
    if (dp[now][fl][cnt] != INF) return dp[now][fl][cnt];
    if (now == 0) dp[now][fl][cnt] = (cnt == 0);
    else {
        if (fl) {
            if ((ub >> now - 1) & 1) dp[now][fl][cnt] = dfs(now - 1, 1, cnt - 1, ub) + dfs(now - 1, 0, cnt, ub);
            else dp[now][fl][cnt] = dfs(now - 1, 1, cnt, ub);
        }
        else dp[now][fl][cnt] = dfs(now - 1, 0, cnt - 1, ub) + dfs(now - 1, 0, cnt, ub);
    }
    return dp[now][fl][cnt];
}
long long calc(long long l, long long r, int cnt) {
    long long res1, res2;
    memset(dp, 0x3f, sizeof(dp));
    res1 = dfs(63, 1, cnt, r);
    memset(dp, 0x3f, sizeof(dp));
    res2 = dfs(63, 1, cnt, l - 1);
    return res1 - res2;
}
long long find(long long l, long long r, int cnt) {
    long long p = l, mid, res;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (calc(p, mid, cnt)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;
}
void syn(long long l, long long r, int cnt) {
    if (l > r) return ;
    while (!calc(l, r, cnt)) cnt += 1;
    ans += calc(l, r, cnt);
    long long p = find(l, r, cnt);
    syn(l, p - 1, cnt + 1);
    return ;
}
void solve() {
    cin >> ql >> qr;
    syn(ql, qr, 1);
    cout << ans << '\n';
    ans = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
1 10 11 100 101 110 111 1000
*/