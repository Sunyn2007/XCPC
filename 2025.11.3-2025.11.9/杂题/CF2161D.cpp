#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
struct syn {
    int n, p;
}a[N + 5];
int t, n, dp[N + 5], pre[N + 5];
struct btr {
    int c[N + 5];
    int lowbit(int x) {
        return x & (-x);
    }
    void build() {
        for (int i = 1; i <= n; i++) 
            c[i] = 0;
    }
    void update(int x, int y) {
        for (int i = x; i <= n; i += lowbit(i))
            c[i] = max(c[i], y);
        return ;
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res = max(res, c[i]);
        return res;
    }
}tr;
bool cmp(syn a, syn b) {
    if (a.n == b.n) return a.p > b.p;
    return a.n < b.n;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i].n, a[i].p = i;
    sort(a + 1, a + n + 1, cmp);
    tr.build();
    for (int i = 1; i <= n; i++) pre[i] = 0;
    int now = 0;
    for (int i = 1; i <= n; i++) {
        while (now < a[i].n) 
            now += 1, pre[now] = pre[now - 1];
        if (now >= 2) dp[i] = max(pre[now - 2], tr.query(n - a[i].p)) + 1;
        else dp[i] = tr.query(n - a[i].p) + 1;
        pre[now] = max(pre[now], dp[i]);
        tr.update(n - a[i].p + 1, dp[i]);
        //cout << a[i].n << ' ' << a[i].p << ' ' << dp[i] << '\n';
    }
    cout << n - pre[now] << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}