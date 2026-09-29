#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
struct syn {
    int id, x, y;
}t1[N + 5], t2[N + 5];
int n, sa[N + 5], rk[N + 5], h[N + 5], cnt[N + 5], len, v, num;
string s1, s2, s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    s = ' ' + s1 + '#' + s2;
    n = s1.size() + s2.size() + 1;
    for (int i = 1; i <= n; i++) 
        rk[i] = s[i], v = max(v, (int)s[i]);
    for (len = 1; len <= n; len <<= 1) {
        for (int i = 1; i <= n; i++)
            t1[i].id = i, t1[i].x = rk[i], t1[i].y = (i + len > n ? 0 : rk[i + len]);
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t1[i].y] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t2[cnt[t1[i].y]--] = t1[i];
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t1[i].x] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t1[cnt[t2[i].x]--] = t2[i];
        num = 0;
        for (int i = 1; i <= n; i++) {
            if (i == 1 || t1[i].x != t1[i - 1].x || t1[i].y != t1[i - 1].y) num += 1;
            rk[t1[i].id] = num;
        }
        if (num == n) break;
        else v = num;
    }
    for (int i = 1; i <= n; i++) sa[rk[i]] = i;
    len = 0;
    for (int i = 1; i <= n; i++) {
        if (rk[i] == 1) len = 0;
        else {
            if (len) len -= 1;
            int j = sa[rk[i] - 1];
            while (i + len <= n && j + len <= n && s[i + len] == s[j + len]) len += 1;
        }
        h[rk[i]] = len;
    }
    //cout << s << '\n';
    int ans = INT_MAX;
    for (int i = 2; i <= n; i++) {
        //cout << sa[i - 1] << ' ' << sa[i] << ' ' << h[i] << '\n';
        if (h[i] && h[i] > h[i - 1] && h[i] > h[i + 1]) {
            if (sa[i - 1] <= s1.size() && sa[i] > s1.size() + 1) ans = min(ans, max(h[i - 1] + 1, h[i + 1] + 1));
            if (sa[i - 1] > s1.size() + 1 && sa[i] <= s1.size()) ans = min(ans, max(h[i - 1] + 1, h[i + 1] + 1));
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}