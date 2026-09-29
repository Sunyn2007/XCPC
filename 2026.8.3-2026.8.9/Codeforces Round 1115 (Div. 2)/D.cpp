#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], c[N + 5];
int syn(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], c[i] = a[i] - a[i - 1];
    int lst = 2;
    for (int i = 3; i <= n; i++)
        if (syn(c[i]) % 2 != syn(c[i - 1]) % 2) {
            sort(c + lst, c + i);
            lst = i;
        }
    sort(c + lst, c + n + 1);
    long long now = 0;
    for (int i = 1; i <= n; i++)
        now += c[i], cout << now << ' ';
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}