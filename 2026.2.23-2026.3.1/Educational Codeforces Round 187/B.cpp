#include <bits/stdc++.h>
using namespace std;
int t, n;
string x;
int calc(string x) {
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += x[i] - '0';
    return res;
}
void upd(string &x) {
    int maxn = 0, resp = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (x[i] - '1' > maxn)
                maxn = x[i] - '1', resp = 1;
        }
        else if (x[i] - '0' > maxn)
            maxn = x[i] - '0', resp = i;
    }
    if (resp == 1) x[1] = '1';
    else x[resp] = '0';
    return ;
}
void solve() {
    cin >> x, n = x.size(), x = ' ' + x;
    int ans = 0;
    while (calc(x) >= 10)
        upd(x), ans += 1;
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