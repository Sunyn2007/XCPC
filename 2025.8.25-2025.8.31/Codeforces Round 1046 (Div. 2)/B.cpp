#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5];
string s;
void solve() {
    cin >> n >> k >> s;
    int len = 0, now = 1;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') len += 1, a[i] = now++;
        else len = 0;
        if (len >= k) flag = false;
    }
    for (int i = 0; i < n; i++)
        if (s[i] == '0') a[i] = now++;
    if (!flag) cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}