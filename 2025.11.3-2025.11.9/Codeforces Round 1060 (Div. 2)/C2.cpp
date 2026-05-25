#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, V = 2e5;
struct syn {
    int n, c;
}a[N + 5];
int t, n;
bool book[V + 5];
vector<int> p[V + 5];
bool cmp(syn a, syn b) {
    return a.c < b.c;
}
void init() {
    for (int i = 2; i <= V + 1; i++) {
        int x = i;
        for (int j = 2; j <= sqrt(x); j++) 
            if (x % j == 0) {
                p[i].push_back(j);
                while (x % j == 0) x /= j;
            }
        if (x > 1) p[i].push_back(x);
    }
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].n;
    for (int i = 1; i <= n; i++) cin >> a[i].c;
    sort(a + 1, a + n + 1, cmp);
    bool flag = false;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < p[a[i].n].size(); j++) {
            if (!book[p[a[i].n][j]])
                book[p[a[i].n][j]] = true;
            else flag = true;
        }
    if (flag) cout << 0 << '\n';
    else {
        long long ans = a[1].c + a[2].c;
        for (int i = 1; i <= n; i++) 
            for (int j = 0; j < p[a[i].n + 1].size(); j++)
                if (book[p[a[i].n + 1][j]]) {
                    ans = min(ans, 1ll * a[i].c);
                    break;
                }
        for (int i = 2; i <= n; i++) 
            for (int j = 0; j < p[a[i].n].size(); j++)
                ans = min(ans, 1ll * (p[a[i].n][j] - a[1].n % p[a[i].n][j]) * a[1].c);
        cout << ans << '\n';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < p[a[i].n].size(); j++)
            book[p[a[i].n][j]] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) solve();
    return 0;
}