#include <bits/stdc++.h>
using namespace std;
int t;
long long n, m, a, b;
long long gcd(long long a, long long b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
void solve() {
    cin >> n >> m >> a >> b;
    if (gcd(n, a) != 1 || gcd(m, b) != 1) {
        cout << "NO" << '\n';
        return ;
    }
    long long cnt = n * m / gcd(n, m);
    //cout << d << ' ' << r << ' ' << cnt << ' ' << n * m << '\n';
    if (2 * cnt >= n * m) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}