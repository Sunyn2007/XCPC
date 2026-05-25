#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, cnt[(N << 1) + 5];
string a, b;
long long sum[(N << 1) + 5], s0[(N << 1) + 5], s1[(N << 1) + 5], pre[(N << 1) + 5], suf[(N << 1) + 5];
void solve() {
    cin >> n >> a >> b;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') cnt0 += 1;
        else cnt1 += 1;
        cnt[cnt0 - cnt1 + n] += 1;
        s0[cnt0 - cnt1 + n] += cnt0;
        s1[cnt0 - cnt1 + n] += cnt1;
    }
    sum[0] = cnt[0];
    for (int i = 1; i <= (n << 1); i++)
        sum[i] = sum[i - 1] + cnt[i];
    pre[0] = s0[0];
    for (int i = 1; i <= (n << 1); i++) 
        pre[i] = pre[i - 1] + s0[i];
    suf[n << 1] = s1[n << 1];
    for (int i = (n << 1) - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + s1[i];
    long long ans = 0;
    cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == '0') cnt0 += 1;
        else cnt1 += 1;
        if ((cnt0 - cnt1) != n) {
            ans += suf[-(cnt0 - cnt1) + n] + cnt1 * (sum[n << 1] - sum[-(cnt0 - cnt1) + n - 1]);
            ans += pre[-(cnt0 - cnt1) + n - 1] + cnt0 * sum[-(cnt0 - cnt1) + n - 1];
        }
        else ans += suf[-(cnt0 - cnt1) + n] + cnt1 * sum[n << 1]; 
    }
    cout << ans << '\n';
    for (int i = 0; i <= (n << 1); i++) cnt[i] = s0[i] = s1[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}