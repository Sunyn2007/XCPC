#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

const i64 MOD = 998244353;

i64 inv[1010];
i64 jc[1010], jc_inv[1010];

void init() {
    jc[0] = jc_inv[0] = 1;
    jc[1] = jc_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 1010; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        jc[i] = jc[i - 1] * i % MOD;
        jc_inv[i] = jc_inv[i - 1] * inv[i] % MOD;
    }
}

i64 f[1010];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%*d%*d");
    }
    int cnt = n - 1;
    for (int i = 1; i <= cnt; ++i) {
        printf("? 1 %d %d\n", n, i);
        fflush(stdout);
        scanf("%lld", f + i);
    }
    printf("!\n");
    fflush(stdout);
    i64 p;
    scanf("%lld", &p);
    if (p <= cnt) {
        printf("%lld\n", f[p]);
    }
    veci64 pre(cnt + 5, 1), suf(cnt + 5, 1);
    pre[0] = p % MOD;
    for (int i = 1; i <= cnt; ++i) {
        pre[i] = pre[i - 1] * (p - i) % MOD;
    }
    suf[cnt] = (p - cnt + MOD) % MOD;
    for (int i = cnt - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] * (p - i) % MOD;
    }
    i64 ans = 0;
    for (int i = 0 ; i <= cnt; ++i) {
        i64 pp = (i ? pre[i - 1] : 1ll);
        i64 tmp = f[i] * pp % MOD * suf[i + 1] % MOD;
        i64 iv = jc_inv[i] * jc_inv[cnt - i] % MOD;
        if ((cnt - i) & 1) iv = MOD - iv;
        ans = (ans + tmp * iv % MOD) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    init();
    // int T;scanf("%d", &T);
    // while(T--) {
        solve();
    // }

    return 0;
}