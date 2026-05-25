#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, d, a[N + 5], b[N + 5], pa[N + 5], pb[N + 5];
long long ans;
int calc(int i, int j) {
    int x = b[i], y = b[j];
    if (pa[y] > pa[x]) return pa[y] - pa[x] - 1;
    else return n - (pa[x] - pa[y] + 1);
}
int syn(int x) {
    return x < 0 ? -x : x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i], pa[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        cin >> b[i], pb[b[i]] = i;
        ans += calc(i - 1, i);
    }
    cout << ans << '\n';
    for (int i = 1; i < d; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 1) {
            int p1 = pb[a[x]], p2 = pb[a[y]];
            ans -= calc(p1 - 1, p1) + calc(p2 - 1, p2);
            if (p1 < n) ans -= calc(p1, p1 + 1);
            if (p2 < n) ans -= calc(p2, p2 + 1);
            if (abs(p1 - p2) == 1) ans += calc(min(p1, p2), max(p1, p2));
            swap(pa[a[x]], pa[a[y]]), swap(a[x], a[y]);
            ans += calc(p1 - 1, p1) + calc(p2 - 1, p2);
            if (p1 < n) ans += calc(p1, p1 + 1);
            if (p2 < n) ans += calc(p2, p2 + 1);
            if (abs(p1 - p2) == 1) ans -= calc(min(p1, p2), max(p1, p2));
        }
        if (c == 2) {
            int p1 = x, p2 = y;
            ans -= calc(p1 - 1, p1) + calc(p2 - 1, p2);
            if (p1 < n) ans -= calc(p1, p1 + 1);
            if (p2 < n) ans -= calc(p2, p2 + 1);
            if (abs(p1 - p2) == 1) ans += calc(min(p1, p2), max(p1, p2));
            swap(pb[b[x]], pb[b[y]]), swap(b[x], b[y]);
            ans += calc(p1 - 1, p1) + calc(p2 - 1, p2);
            if (p1 < n) ans += calc(p1, p1 + 1);
            if (p2 < n) ans += calc(p2, p2 + 1);
            if (abs(p1 - p2) == 1) ans -= calc(min(p1, p2), max(p1, p2));
        }
        cout << ans << '\n';
    }
    return 0;
}