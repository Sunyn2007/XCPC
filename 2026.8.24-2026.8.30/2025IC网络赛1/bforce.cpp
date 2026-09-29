#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

bool vis[1010];

i64 cal(int n, int s) {
    for (int i = 1; i <= n; ++i)
        vis[i] = 1;
    for (int i = 0; i < n; ++i) {
        if((s >> i) & 1) {
            vis[i + 1] = 0;
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if(vis[i] && vis[j]) {
                ans += std::__gcd(n, j - i);
            }
        }
    }
    return ans;
}

int lowbit(int x) {
    return x & (-x);
}

void solve(int n) {
    int cov = (1 << n);
    veci64 ans(n + 2, LLONG_MAX);
    veci sta(n + 2);
    for (int s = 0; s < cov; ++s) {
        int k = std::__popcount(s);
        i64 tmp = cal(n, s);
        if(tmp < ans[k]) {
            ans[k] = tmp;
            sta[k] = s;
        }
    }
    for (int k = 1; k <= n; ++k) {
        printf("[n = %2d, k = %2d] %4lld | %10d\n", n, k, ans[k], sta[k]);
        assert(lowbit(sta[k] + 1) == sta[k] + 1);
    }
}

int main() {
    for (int n = 1; n <= 20; ++n) {
        solve(n);
    }
    

    return 0;
}