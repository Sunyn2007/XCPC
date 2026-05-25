#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, V = 2e5;
int t, n, a[N + 5], b[N + 5], book[N + 5];
vector<int> p[N + 5];
void solve() {
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) cnt += 1;
        if (a[i] > 1) p[i].push_back(a[i]), book[a[i]] += 1;
        for (int j = 2; j <= sqrt(a[i]); j++)
            if (a[i] % j == 0) {
                p[i].push_back(j), book[j] += 1;
                if (a[i] / j != j) p[i].push_back(a[i] / j), book[a[i] / j] += 1;
            }
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (cnt >= 2) cout << 0 << '\n';
    else if (cnt == 1) {
        bool flag = false;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < p[i].size(); j++)
                if (book[p[i][j]] >= 2) flag = true;
        if (flag) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    else {
        bool flag0 = false, flag1 = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < p[i].size(); j++) {
                if (book[p[i][j]] >= 2) flag0 = true;
                book[p[i][j]] -= 1;
            }
            int num = a[i] + 1;
            if (book[num]) flag1 = true;
            for (int j = 2; j <= sqrt(num); j++)
                if (num % j == 0) {
                    if (book[j]) flag1 = true;
                    if (book[num / j]) flag1 = true;
                }
            for (int j = 0; j < p[i].size(); j++)
                book[p[i][j]] += 1;
        }
        if (flag0) cout << 0 << '\n';
        else if (flag1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < p[i].size(); j++)
            book[p[i][j]] -= 1;
        p[i].clear();
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}