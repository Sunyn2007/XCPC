#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, m;
bool flag = true;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    int p1 = 1, p2 = 1, ans = 0;
    while (p1 <= n && p2 <= m) {
        if (s[p1] == t[p2]) p1 += 1, p2 += 1;
        else {
            if (t[p2] == 'A') p2 += 1, ans += 1;
            else {
                if (s[p1] == 'A') p1 += 1, ans += 1;
                else {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag) {
        while (p1 <= n && s[p1] == 'A') p1 += 1, ans += 1;
        while (p2 <= m && t[p2] == 'A') p2 += 1, ans += 1;
        if (p1 <= n || p2 <= m) flag = false;
    }
    if (flag) cout << ans;
    else cout << -1;
    return 0;
}