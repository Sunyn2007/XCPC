#include <bits/stdc++.h>
using namespace std;
string lps(const string &s) {
    int n = s.size();
    vector<int> nxt(n + 1);
    nxt[0] = -1;
    int i = 0, j = -1;
    while (i < n) {
        if (j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
    if (nxt[n] == 0) return "empty";
    return s.substr(0, nxt[n]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        cout << lps(str) << '\n';
    }
    return 0;
}
