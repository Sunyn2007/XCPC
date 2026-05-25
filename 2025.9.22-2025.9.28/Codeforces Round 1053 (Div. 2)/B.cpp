#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 1e5;
int t, n, m, a[M + 5];
string s;
map<int, bool> book;
vector<int> ans;
void solve() {
    cin >> n >> m >> s, s = ' ' + s;
    for (int i = 1; i <= m; i++)
        cin >> a[i], book[a[i]] = true, ans.push_back(a[i]);
    int now = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            if (book.find(now + 1) == book.end()) ans.push_back(now + 1);
            book[now + 1] = true;
            now += 1;
        }
        if (s[i] == 'B') {
            while (book.find(now + 1) != book.end()) now += 1;
            now += 1, book[now] = true, ans.push_back(now);
            while (book.find(now + 1) != book.end()) now += 1;
            now += 1;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
    book.clear(), ans.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}