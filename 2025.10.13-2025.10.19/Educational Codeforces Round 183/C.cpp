#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
map<int, int> book;
void solve() {
    cin >> n >> s, s = ' ' + s;
    int cnta = 0, cntb = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') cnta += 1;
        else cntb += 1;
    }
    if (!cnta || !cntb) cout << -1 << '\n';
    else if (cnta == cntb) cout << 0 << '\n';
    else {
        int now = 0, det = cnta - cntb, ans = n;
        book[now] = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'a') now += 1;
            else now -= 1;
            if (book.find(now - det) != book.end()) 
                ans = min(ans, i - book[now - det]);
            book[now] = i;
        }
        cout << (ans == n ? -1 : ans) << '\n';
    }
    book.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}