#include <bits/stdc++.h>
using namespace std;

static constexpr int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n), pos(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];

        // pos[x]：A_x 在 f_p(A) 中出现的位置
        pos[p[i]] = i;
    }

    // need[i]：拓扑序中必须出现在 i 前面的点
    vector<uint32_t> need(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // 原来 i 在 j 前面，洗牌后 i 在 j 后面
            if (pos[i] > pos[j]) {
                // 要求 A_i > A_j
                // 按数值递增排列位置时，j 必须在 i 前面
                need[i] |= (1u << j);
            }
        }
    }

    uint32_t total = 1u << n;
    uint32_t full = total - 1;

    vector<int> dp(total, 0);
    dp[0] = 1;

    for (uint32_t mask = 0; mask < total; ++mask) {
        if (dp[mask] == 0) {
            continue;
        }

        uint32_t missing = full ^ mask;
        uint32_t candidates = missing;

        while (candidates) {
            uint32_t bit = candidates & -candidates;
            candidates -= bit;

            int v = __builtin_ctz(bit);

            // need[v] 中不能还有未选择的点
            if ((need[v] & missing) == 0) {
                int &next = dp[mask | bit];
                next += dp[mask];

                if (next >= MOD) {
                    next -= MOD;
                }
            }
        }
    }

    cout << 2LL * dp[full] % MOD << '\n';
    return 0;
}