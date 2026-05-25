#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n;
char s[N + 5];
void solve() {
    cin >> (s + 1), n = strlen(s + 1);
    int now = 1, cnt = 0, mx = 0;
    while (now <= n) {
        if (now < n && s[now + 1] == s[now]) {
            cnt += 1;
            int tmp = 1;
            while (now < n && s[now + 1] == s[now]) now += 1, tmp += 1;
            mx = max(mx, tmp);
        }
        now += 1;
    }
    if (mx >= 4) cout << "NO" << '\n';
    else if (mx == 3) {
        if (cnt == 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else if (mx == 2) {
        if (cnt <= 2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else cout << "YES" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}