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
    if (j >= m) return i - m + 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;
        vector<int> nxt = getNext(p);
        for (int i = 0; i < (int)nxt.size(); ++i) {
            if (i) cout << ' ';
            cout << nxt[i];
        }
        cout << '\n';
        cout << kmp(s, p, nxt) << '\n';
    }
    return 0;
}
