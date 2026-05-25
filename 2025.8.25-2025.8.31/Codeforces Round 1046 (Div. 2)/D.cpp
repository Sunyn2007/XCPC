#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const long long K = 1e9;
int t, n;
long long x[N + 5], y[N + 5], tmp, d1, d2;
long long syn(long long x) {
    return x < 0 ? -x : x;
}
long long dis(long long x1, long long y1, long long x2, long long y2) {
    return syn(x1 - x2) + syn(y1 - y2);
}
void mkq(char ch, long long k) {
    cout << '?' << ' ' << ch << ' ' << k << '\n';
    cout.flush();
    cin >> tmp;
    return ;
}
void solve() {
    long long a = -K, b = -K, c = -K, d = K;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        if (dis(K, K, x[i], y[i]) < dis(K, K, a, b))
            a = x[i], b = y[i];
        if (dis(K, -K, x[i], y[i]) < dis(K, -K, c, d))
            c = x[i], d = y[i];
    }
    mkq('R', K), mkq('R', K);
    mkq('U', K), mkq('U', K), d1 = tmp;
    mkq('D', K), mkq('D', K);
    mkq('D', K), mkq('D', K), d2 = tmp;
    long long chg = d2 - (d1 + (a - c)), res = (4 * K - (b - d) - chg) / 2;
    long ansy = b + res - 2 * K, ansx = a + (d1 - res) - 2 * K;
    //cout << chg << ' ' << res << '\n';
    cout << '!' << ' ' << ansx << ' ' << ansy << '\n';
    cout.flush();
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
x + x + chg + b - d = 4 * K
2000000100, 199999994000001
4000000199 
4000000001
*/