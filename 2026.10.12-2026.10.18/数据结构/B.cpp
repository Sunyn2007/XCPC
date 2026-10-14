#include <bits/stdc++.h>
using namespace std;
vector<int> getNext(const string &p) {
    int n = p.size();
    vector<int> nxt(n);
    nxt[0] = -1;
    int i = 0, j = -1;
    while (i < n - 1) {
        if (j == -1 || p[i] == p[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
    return nxt;
}
int kmp(const string &s, const string &p, const vector<int> &nxt) {
    int n = s.size(), m = p.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = nxt[j];
        }
    }
    if (j >= m) return i - m;
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s, p, r;
        cin >> s >> p >> r;
        string res = s;
        int pos = kmp(s, p, getNext(p));
        if (pos != -1) res = s.substr(0, pos) + r + s.substr(pos + p.size());
        cout << s << '\n' << res << '\n';
    }
    return 0;
}
