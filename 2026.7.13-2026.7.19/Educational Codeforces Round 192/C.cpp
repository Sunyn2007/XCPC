#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, k, a[N + 5], book[N + 5];
set<int> s;
map<int, bool> flag;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]), book[a[i]] += 1;
    }
    int ans = 0;
    while (!s.empty()) {
        if ((k - n) >= 0 && (k - n) % s.size() == 0 && flag.find(s.size()) == flag.end()) 
            ans += 1, flag[s.size()] = true;
        for (auto it = s.begin(); it != s.end(); ) {
            book[*it] -= 1, n -= 1;
            if (book[*it] == 0) it = s.erase(it);
            else it++;
        }
    }
    cout << ans << '\n';
    flag.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}