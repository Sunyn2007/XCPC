#include <bits/stdc++.h>
using namespace std;
int cnt(const string &s, const string &p) {
    int n = s.size(), m = p.size();
    vector<int> nx(m + 1);
    nx[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || p[i] == p[j]) nx[++i] = ++j;
        else j = nx[j];
    }
    int res = 0;
    j = 0;
    for (i = 0; i < n; ++i) {
        while (j != -1 && s[i] != p[j]) j = nx[j];
        ++j;
        if (j == m) {
            ++res;
            j = nx[m];
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string p;
        cin >> p;
        int n;
        cin >> n;
        while (n--) {
            string q;
            cin >> q;
            cout << q << ':' << cnt(p, q) << '\n';
        }
    }
    return 0;
}
