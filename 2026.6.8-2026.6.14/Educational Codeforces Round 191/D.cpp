#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], b[N + 5], cnt, tot;
map<int, vector<int> > p;
bool check(int x, int y) {
    if (x == y || x < 1 || x > n || y < 1 || y > n) return false;
    int tmp = cnt;
    if (x - y == 1 || x - y == -1) {
        if (x > y) swap(x, y);
        if (x > 1 && a[x] != a[x - 1]) tmp -= 1;
        if (y < n && a[y] != a[y + 1]) tmp -= 1;
        if (x > 1 && a[y] != a[x - 1]) tmp += 1;
        if (y < n && a[x] != a[y + 1]) tmp += 1;
    }
    else {
        if (x > 1 && a[x] != a[x - 1]) tmp -= 1;
        if (x < n && a[x] != a[x + 1]) tmp -= 1;
        if (y > 1 && a[y] != a[y - 1]) tmp -= 1;
        if (y < n && a[y] != a[y + 1]) tmp -= 1;
        if (x > 1 && a[y] != a[x - 1]) tmp += 1;
        if (x < n && a[y] != a[x + 1]) tmp += 1;
        if (y > 1 && a[x] != a[y - 1]) tmp += 1;
        if (y < n && a[x] != a[y + 1]) tmp += 1;
    }
    return tmp == tot - 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        p[a[i]].push_back(i);
        if (i > 1 && a[i] != a[i - 1]) cnt += 1;
    }
    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - (b + 1);
    if (cnt == tot - 1) cout << "YES" << '\n';
    else {
        bool ans = false;
        for (int i = 1; i <= tot; i++) {
            vector<int> tmp = p[b[i]];
            if (tmp.size() == 1) continue;
            ans |= check(tmp[0], tmp[1] - 1), ans |= check(tmp[0], tmp.back() + 1);
            ans |= check(tmp.back(), tmp[0] - 1), ans |= check(tmp.back(), tmp[tmp.size() - 2] + 1);
            if (tmp.size() >= 3) {
                if (tmp.back() - tmp[1] + 1 == tmp.size())
                    for (int j = tmp[1]; j <= tmp.back(); j++)
                        if (a[j] != b[i]) ans |= check(tmp[0], j);
                if (tmp[tmp.size() - 2] - tmp[0] + 1 == tmp.size())
                    for (int j = tmp[0]; j <= tmp[tmp.size() - 2]; j++)
                        if (a[j] != b[i]) ans |= check(tmp.back(), j);
            }
        }
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    p.clear(), cnt = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}