#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

const i64 MOD = 998244353;
i64 jc[600010], inv[600010], jc_inv[600010];
void init() {
    jc[0] = jc_inv[0] = 1;
    jc[1] = inv[1] = jc_inv[1] = 1;
    for (int i = 2; i < 600010; ++i) {
        jc[i] = jc[i - 1] * i % MOD;
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        jc_inv[i] = jc_inv[i - 1] * inv[i] % MOD;      
    }
}

i64 choose(int n, int m) {
    return jc[n] * jc_inv[m] % MOD * jc_inv[n - m] % MOD;
}

int n, m, K;

i64 cal(int s, int t) {
    int d = std::abs(s - t);
    if(d > m)
        return 0;
    if((d & 1) != (m & 1))
        return 0;
    printf("choose %d %d \n", m, (m + d) >> 1);
    return choose(m, (m + d) >> 1);
}

int p[100];

i64 calx() {
    printf("calx()\n");
    int L = INT_MAX;
    int R = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        L = std::min(L, p[i]);
        R = std::max(R, p[i]);
    }
    L -= m;
    R += m;
    int LEN = R - L + 1;
    std::vector<veci64> f(n + 2);
    for (int x = 1; x <= n; ++x) {
        f[x].resize(LEN);
        for (int d = 0; d < LEN; ++d) {
            int t = L + d;
            f[x][d] = cal(p[x], t);
        }
        for (int d = 1; d < LEN; ++d) {
            f[x][d] += f[x][d - 1];
            if(f[x][d] >= MOD)
                f[x][d] -= MOD;
        }
    }


    auto sum = [&f](int x, int p, int q)-> i64 {
        if(p <= 0)
            return f[x][q];
        return f[x][q] - f[x][p - 1];
    };

    std::vector<veci64> dp(K + 1);
    for (int t = 0; t <= K; ++t) {
        dp[t].resize(LEN);
        for (int d = 0; d < LEN; ++d) {
            int st = L + d;
            int ed = st + t;
            if (ed > R)
                break;
            dp[t][d] = 1;
            for (int x = 1; x <= n; ++x) {
                dp[t][d] = dp[t][d] * sum(x, st - L, ed - L) % MOD;
                if(dp[t][d] == 0)
                    break;
            }
        }
    }


    i64 ans = 0;

    // t == 0
    for (int d = 0; d < LEN; ++d) {
        int st = L + d;
        ans += dp[0][d];
        if(ans >= MOD)
            ans -= MOD;
    }
    // t > 0
    for (int t = 1; t <= K; ++t) {
        for (int d = 0; d < LEN; ++d) {
            int st = L + d;
            int ed = st + t;
            if(ed > R)
                break;
            i64 tmp = dp[t][d] - dp[t - 1][d] - dp[t - 1][d + 1];
            if(t >= 2)
                tmp += dp[t - 2][d + 1];
            tmp = (tmp + MOD + MOD) % MOD;
            ans += tmp;
            if(ans >= MOD)
                ans -= MOD;
        }
    }
    printf("ans = %lld\n", ans);

    return ans;
}

int main() {
    init();
    scanf("%d%d%d", &n, &m, &K);
    std::vector<std::pair<int, int> > pnt(n + 2);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &pnt[i].first, &pnt[i].second);
    }

    i64 ans = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = pnt[i].first + pnt[i].second;
    }
    ans = ans * calx() % MOD;
    printf("ans = %lld\n", ans);
    for (int i = 1; i <= n; ++i) {
        p[i] = pnt[i].first - pnt[i].second;
    }
    ans = ans * calx() % MOD;
    printf("ans = %lld\n", ans);
    printf("%lld\n", ans);
    

    return 0;
}