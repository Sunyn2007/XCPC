#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, K = 1e5;
int n, k, c[K + 5], ans[N + 5];
map<string, int> bk;
struct team {
    int w, id;
    string u;
}a[N + 5];
bool cmp(team a, team b) {
    return a.w > b.w;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int minc = INT_MAX;
    for (int i = 1; i <= k; i++) cin >> c[i], minc = min(minc, c[i]); 
    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].u, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    int rk = 0;
    for (int i = 1; i <= n; i++) {
        if (bk[a[i].u] < minc) {
            bk[a[i].u] += 1;
            rk += 1;
        }
        ans[a[i].id] = rk;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}