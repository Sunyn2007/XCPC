#include <cstdio>
#include <algorithm>
typedef long long i64;

bool vis[1010];

int main() {
    int n, k;scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        vis[i] = 1;
    for (int i = 1; i <= k; ++i) {
        int x;scanf("%d", &x);
        vis[x] = 0;
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if(vis[i] && vis[j]) {
                ans += std::__gcd(n, j - i);
            }
        }
    }
    printf("sum :%lld\n", ans);

    return 0;
}