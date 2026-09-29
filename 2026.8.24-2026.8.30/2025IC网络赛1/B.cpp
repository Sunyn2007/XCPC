#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

int main() {
    int n, k;scanf("%d%d", &n, &k);
    // veci64 val(n + 2);
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         if(i == j) continue;
    //         val[i] += std::__gcd(n, std::abs(i - j));
    //     }
    // }

    // veci del(n + 2);

    // for (int rnd = 1; rnd <= k; ++rnd) {
    //     int mxi = 0;
    //     for (int i = 1; i <= n; ++i) {
    //         if(del[i])
    //             continue;
    //         if(val[i] > val[mxi])
    //             mxi = i;
    //     }
    //     del[mxi] = 1;
    //     for (int i = 1; i <= n; ++i) {
    //         if(del[i])
    //             continue;
    //         val[i] -= std::__gcd(n, std::abs(i - mxi));
    //     }
    // }

    // for (int i = 1; i <= n; ++i) {
    //     if(del[i])
    //         printf("%d ", i);
    // }
    // printf("\n");

    for (int i = 1; i <= k; ++i)
        printf("%d ", i);
    printf("\n");

    return 0;
}