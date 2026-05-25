#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5];
map<int, bool> book, flag;
vector<int> ans;
void solve() {
    bool ok = true;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) book[a[i]] = true, flag[a[i]] = false;
    for (int i = 1; i <= n; i++) 
        if (!flag[a[i]]) {
            ans.push_back(a[i]);
            int x = a[i];
            while (x <= k) {
                if (book.find(x) != book.end())
                    flag[x] = true;
                else {
                    ok = false;
                    break;
                }
                x += a[i];
            }
            if (!ok) break;
        }
    if (ok) {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) 
            cout << ans[i] << ' ';
        cout << '\n';
    }
    else cout << -1 << '\n';
    book.clear(), flag.clear(), ans.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}