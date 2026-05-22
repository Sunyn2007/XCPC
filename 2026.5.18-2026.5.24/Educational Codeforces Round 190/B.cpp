#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, cnt[N + 5];
char s[N + 5];
void solve() {
    cin >> (s + 1), n = strlen(s + 1);
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        if (s[i] == '1' || s[i] == '3') cnt[i] += 1;
        if (s[i] == '4') tmp += 1;
    }
    int ans = INT_MAX;
    for (int i = n; i >= 1; i--)
        if (s[i] == '2') {
            ans = min(ans, tmp + cnt[i - 1]);
            tmp += 1;
        }
    ans = min(ans, tmp);
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}