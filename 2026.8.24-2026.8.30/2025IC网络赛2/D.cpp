#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

const i64 MOD = 998244353;
const i64 inv2 = 499122177;

i64 pow(i64 a, i64 b) {
    i64 ans = 1;
    for (;b;b>>=1) {
        if(b&1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

void solve() {
    int n;scanf("%d", &n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    std::sort(a.begin() + 1, a.begin() + n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        i64 tmp = pow(3, i - 1) + 1;
        tmp = tmp * inv2 % MOD;
        tmp = tmp * pow(2, n - i) % MOD;
        tmp = tmp * a[i] % MOD;
        ans = (ans + tmp) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}