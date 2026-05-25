#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
struct syn {
    int id, x, y;
}t1[N + 5], t2[N + 5];
int t, n, l, k, sa[N + 5], rk[N + 5], cnt[N + 5], len, v, num, h[N + 5], st[N + 5][21], lg[N + 5];
char s[N + 5];
vector<pair<int, int>> tmp;
void init() {
    for (int i = 2; i <= N; i++) 
        lg[i] = lg[i >> 1] + 1;
    return ;
}
int qry(int l, int r) {
    int len = r - l + 1, x = lg[len];
    return min(st[l][x], st[r - (1 << x) + 1][x]);
}
void solve() {
    cin >> n >> l >> k >> (s + 1);
    if (n / l < k) {
        cout << "NO" << '\n';
        return ;
    }
    if (k == 1) {
        cout << "YES" << '\n' << (s + 1) << '\n';
        return ;
    }
    v = 0;
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
    for (int i = 1; i <= n; i++) st[i][0] = h[i];
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j + (1 << i - 1) <= n; j++)
            st[j][i] = min(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
    for (int i = 1; i <= n; i++) {
        if (i == 1) tmp.push_back(make_pair(i, n - (k - 1) * l));
        else if (i > l) {
            if (n - i + 1 >= l && (i - 1) / l + 1 >= k) tmp.push_back(make_pair(i, n));
            else if (i + l - 1 < n - l + 1 && (i - 1) / l + (n - i - l + 1) / l + 1 >= k) tmp.push_back(make_pair(i, n - (k - 1 - (i - 1) / l) * l));
        }
    }
    int ansl = tmp[0].first, ansr = tmp[0].second;
    for (int i = 1; i < tmp.size(); i++) {
        int l = tmp[i].first, r = tmp[i].second;
        int lcp = qry(min(rk[ansl], rk[l]) + 1, max(rk[ansl], rk[l]));
        //cout << ansl << ' ' << ansr << ' ' << l << ' ' << r << ' ' << lcp << '\n';
        if (lcp >= min(ansr - ansl + 1, r - l + 1) && r - l + 1 > ansr - ansl + 1) ansl = l, ansr = r;
        if (lcp < min(ansr - ansl + 1, r - l + 1) && s[l + lcp] > s[ansl + lcp]) ansl = l, ansr = r;
    }
    tmp.clear();
    cout << "YES" << '\n';
    for (int i = ansl; i <= ansr; i++) cout << s[i];
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) solve();
    return 0;
}