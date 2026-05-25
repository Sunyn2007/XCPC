#include <bits/stdc++.h>
using namespace std;
string s;
int n, book[30], maxn;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s, n = s.size(), s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        book[s[i] - 'a'] += 1;
        maxn = max(maxn, book[s[i] - 'a']);
    }
    for (int i = 1; i <= n; i++)
        if (book[s[i] - 'a'] != maxn) cout << s[i];
    return 0;
}