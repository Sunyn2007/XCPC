#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

void solve() {
    int n;scanf("%d", &n);
    veci64 a(n * 2);
    for (int i = 0 ; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = n; i < n * 2; ++i)
        a[i] = a[i - n];
    if(n == 1) {
        printf("%lld\n", a[0]);
        return;
    }
    i64 ans = LLONG_MAX;
    for (i64 i = n + 1, cur=0, mn=LLONG_MAX; ; ++i) {
        if(i - n >= n)
            break;
        cur += a[i] + a[i - 1];
        mn = std::min(mn, a[i] + a[i - 1]);
        i64 rest = n - 1 - (i - n);
        // printf("%lld %lld %lld %lld\n", cur, mn, rest, cur + mn * rest);
        ans = std::min(ans, cur + mn * rest);
    }
    for (i64 i = n - 1, cur=0, mn=LLONG_MAX; ; --i) {
        if(n - i >= n)
            break;
        cur += a[i] + a[i + 1];
        mn = std::min(mn, a[i] + a[i + 1]);
        i64 rest = n - 1 - (n - i);
        // printf("%lld %lld %lld %lld\n", cur, mn, rest, cur + mn * rest);
        ans = std::min(ans, cur + mn * rest);
    }
    printf("%lld\n", ans + a[0]);
}

int main() {
    int T;scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}