#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

int main() {
    int n, m;scanf("%d%d", &n, &m);
    veci64 sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            i64 x;scanf("%lld", &x);
            sum[i] += x;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if(sum[i] < sum[i - 1])
            ++ans;
    printf("%d\n", ans);

    return 0;
}