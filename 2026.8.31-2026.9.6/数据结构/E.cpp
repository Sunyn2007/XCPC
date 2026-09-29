#include <bits/stdc++.h>
using namespace std;
struct node {
    string date;
    int y, m, d, s1, s2;
    bool operator<(const node& o) const {
        if (y != o.y) return y < o.y;
        if (m != o.m) return m < o.m;
        return d < o.d;
    }
}op[10005], cl[10005];
int n, k, c1, c2;
void syn(string s, int &y, int &m, int &d) {
    y = m = d = 0;
    int i = 0;
    while(s[i] != '/') y = y * 10 + (s[i++] - '0'); i++;
    while(s[i] != '/') m = m * 10 + (s[i++] - '0'); i++;
    while(i < s.length()) d = d * 10 + (s[i++] - '0');
}
void solve(node a[], int cnt, string type) {
    sort(a + 1, a + cnt + 1);
    for (int i = k; i <= cnt; ++i) {
        int sum1 = 0, sum2 = 0;
        for (int j = i - k + 1; j <= i; ++j) {
            sum1 += a[j].s1;
            sum2 += a[j].s2;
        }
        cout << a[i].date << " " << type << " " << sum1 / k << " " << sum2 / k << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (cin >> n >> k) {
        for (int i = 1; i <= n; ++i) {
            string dt, type;
            int s1, s2, y, mt, d;
            cin >> dt >> type >> s1 >> s2;
            syn(dt, y, mt, d);
            if (type == "open") op[++c1] = {dt, y, mt, d, s1, s2};
            else cl[++c2] = {dt, y, mt, d, s1, s2};
        }
        solve(op, c1, "open");
        solve(cl, c2, "close");
    }
    return 0;
}