#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, K = 100;
int t, k, n, nxt[N + N + K + 100];
string s1, s2, s3 = "Rounddo";
void solve() {
    cin >> s1 >> k, n = s1.size();
    s2 = s3, s2.append(k, 'g');
    s1 = ' ' + s2 + '#' + s1 + s1;
    for (int i = 2; i < s1.size(); i++) {
        int j = nxt[i - 1];
        while (j && s1[j + 1] != s1[i]) j = nxt[j];
        if (s1[i] == s1[j + 1]) j += 1;
        nxt[i] = j;
    }
    int cnt = 0;
    for (int i = 7 + k + 2; i < s1.size() - n + (k + 6); i++)
        if (nxt[i] == k + 7) cnt += 1;
    if (cnt > 1) cout << n << '\n';
    else if (cnt == 1) cout << n - (k + 6) << '\n';
    else cout << 0 << '\n';
    for (int i = 2; i < s1.size(); i++) nxt[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}