#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k;
char ans[N + 5];
string s;
void solve() {
    cin >> n >> k >> s, s = ' ' + s;
    int l1 = 0, r1 = n + 1, l2 = 0, r2 = n + 1;
    for (int i = 1; i <= k; i++) {
        if (s[i] == '0') l1 += 1, l2 += 1;
        if (s[i] == '1') r1 -= 1, r2 -= 1;
        if (s[i] == '2') l2 += 1, r2 -= 1;
    }
    for (int i = 1; i <= n; i++)
        if (i <= l1 || i >= r1) ans[i] = '-';
    for (int i = l1 + 1; i <= r1 - 1; i++) {
        if (r2 <= l1 + 1 || l2 >= r1 - 1) ans[i] = '-';
        else if (i <= l2 || i >= r2) ans[i] = '?';
        else ans[i] = '+';
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
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