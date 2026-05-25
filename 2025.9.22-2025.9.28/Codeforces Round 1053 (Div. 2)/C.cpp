#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[(N << 1) + 5], b[(N << 1) + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (i >= 2) b[i - 1] = a[i] - a[i - 1];
    }
    int sum1 = 0, sum2 = 0;
    long long ans = 0;
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (i % 2 == 1) sum1 += b[i];
        else sum2 += b[i];
    }
    ans = sum1;
    cout << ans << ' ';
    sum1 -= b[1] + b[2 * n - 1];
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            ans = ans + 2 * sum2; 
            sum2 -= b[i] + b[2 * n - i];
        }
        else {
            ans = ans + 2 * sum1;
            sum1 -= b[i] + b[2 * n - i];
        }
        cout << ans << ' ';
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
1 2 3 4 5 4 3 2 1 -- 5
1 2 3 4 3 4 3 2 1 -- 4
1 2 3 2 3 2 3 2 1 -- 3
1 2 1 2 1 2 1 2 1 -- 2
1 0 1 0 1 0 1 0 1 -- 1
*/