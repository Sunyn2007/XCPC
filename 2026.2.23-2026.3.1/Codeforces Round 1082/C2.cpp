#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, a[N + 5], stk[N + 5], top = 0, pr[N + 5];
long long f[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    stk[++top] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1] + 1)
            while (top) pr[stk[top--]] = i - 1;
        else
            while (top) {
                if (a[stk[top]] >= a[i]) pr[stk[top--]] = i - 1;
                else break;
            }
        stk[++top] = i;
    }
    while (top) pr[stk[top--]] = n;
    long long ans = 0;
    f[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        f[i] = f[pr[i] + 1] + (n - i + 1);   
        ans += f[i];
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}