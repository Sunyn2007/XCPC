#include <bits/stdc++.h>
using namespace std;
const int N = 5e3;
int t, n, q, a[N + 5];
bool used[N + 5], blk[N + 5];
map<int, int> bk, res;
vector<int> tk;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], bk[a[i]] += 1;
    sort(a + 1, a + n + 1);
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == now) now += 1, used[i] = true;
        else if (a[i] > now) break;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < now && bk[a[i]] > 1) tk.push_back(now + a[i]), bk[a[i]] = 0;
        if (a[i] > now && bk[a[i]]) tk.push_back(now + a[i]), bk[a[i]] = 0;
    }
    for (auto k : tk) {
        vector<int> b[N + 5];
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            if (a[i] < n) b[a[i]].push_back(i);
            if (k - a[i] < n && k - a[i] >= 0) b[k - a[i]].push_back(i);
        }
        int mex = now;
        while (mex < n) {
            bool flag = false;
            for (auto i : b[mex])
                if (!blk[i]) {
                    flag = true, mex += 1, blk[i] = true;
                    break;
                }
            if (!flag) break;
        }
        res[k] = mex;
        for (int i = 1; i <= n; i++) blk[i] = false;
    }
    int ans = 0;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int qk;
        cin >> qk;
        if (res.find(qk) != res.end()) ans ^= res[qk];
        else ans ^= now;
    }
    cout << ans << '\n';
    bk.clear(), tk.clear(), res.clear();
    for (int i = 1; i <= n; i++) used[i] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
}