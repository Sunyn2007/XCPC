#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int t, n, a[N + 5], ans[N + 5];
pair<int, int> f[N + 5];
void mkq(int a, int b) {
    cout << '?' << ' ' << a << ' ' << 2 << ' ' << a << ' ' << b << '\n';
    cout.flush();
    return ;
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << '?' << ' ' << i << ' ' << n << ' ';
        for (int j = 1; j <= n; j++)
            cout << j << ' ';
        cout << '\n', cout.flush();
        cin >> f[i].first;
        f[i].second = i;
    }
    sort(f + 1, f + n + 1);
    int cnt = 0;
    ans[++cnt] = n;
    for (int i = n - 1; i >= 1; i--)
        if(f[i].first == f[ans[cnt]].first - 1) {
            mkq(f[ans[cnt]].second, f[i].second);
            int x;
            cin >> x;
            if (x == 2) ans[++cnt] = i;
        }
    cout << '!' << ' ' << cnt << ' ';
    for (int i = 1; i <= cnt; i++)
        cout << f[ans[i]].second << ' ';
    cout << '\n', cout.flush();
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}