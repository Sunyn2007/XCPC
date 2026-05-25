#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, M = 5e5, MOD = 998244353;
struct syn {
    int v, p;
}a[N + 5];
int t, n, m, k[M + 5], b[N + 5], ans, ll[N + 5], rr[N + 5], c[N + 5], stk[N + 5], top;
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}
bool cmp(syn a, syn b) {
    return a.v < b.v;
}
int add(int x, int y) {
    int res = x + y;
    if (res >= MOD) res -= MOD;
    if (res < 0) res += MOD;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v, a[i].p = i;
        b[i] = qpow(a[i].v, MOD - 2);
    }
    for (int i = 1; i <= m; i++) cin >> k[i];
    for (int i = 1; i <= n; i++) {
        while (top && a[stk[top]].v > a[i].v)
            rr[stk[top--]] = i;
        stk[++top] = i;
    }
    while (top) rr[stk[top--]] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top && a[stk[top]].v >= a[i].v)
            ll[stk[top--]] = i;
        stk[++top] = i;
    }
    while (top) ll[stk[top--]] = 0;
    int tmp1 = 0;
    for (int i = 1; i <= n; i++) {
        c[i] = 1ll * (rr[i] - i) * (i - ll[i]) % MOD;
        tmp1 = add(tmp1, 1ll * b[i] * c[i] % MOD);
        ans = add(ans, 1ll * b[i] * i % MOD * (n - i + 1) % MOD);
    }
    sort(a + 1, a + n + 1, cmp);
    int now = 0, tmp2 = 0;
    for (int i = 1; i <= m; i++) {
        ans = add(ans, 1ll * (k[i] - k[i - 1]) * tmp2 % MOD);
        while (now < n && k[i] + 1 > a[now + 1].v) {
            now += 1;
            ans = add(ans, -1ll * (k[i - 1] + 1) * b[a[now].p] % MOD * c[a[now].p] % MOD);
            tmp1 = add(tmp1, -1ll * b[a[now].p] * c[a[now].p] % MOD);
            ans = add(ans, 1ll * (k[i] - (a[now].v - 1) + 1) * c[a[now].p] % MOD);
            tmp2 = add(tmp2, c[a[now].p]);
        }
        ans = add(ans, 1ll * (k[i] - k[i - 1]) * tmp1 % MOD);
        cout << ans << '\n';
    }
    return 0;
}