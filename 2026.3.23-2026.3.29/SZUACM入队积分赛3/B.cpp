#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 1e5, K = 1e5;
int n, m, k, l[M + 5], r[M + 5], d[M + 5];
long long a[N + 5], cnt[N + 5], sum[N + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i] >> d[i];
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x] += 1, cnt[y + 1] -= 1;
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
        sum[l[i]] += cnt[i] * d[i];
        sum[r[i] + 1] -= cnt[i] * d[i];
    }
    for (int i = 1; i <= n; i++) 
        sum[i] = sum[i - 1] + sum[i], cout << a[i] + sum[i] << ' ';
    return 0;
}