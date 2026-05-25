#include <bits/stdc++.h>
using namespace std;
int t, n;
long long m;
long long syn(long long x) {
    int cnt = 0;
    while (x) {
        x >>= 1;
        cnt += 1;
    }
    return 1ll << cnt;
}
int getp(long long x) {
    int cnt = 0;
    while (x) {
        if ((x & 1) && (x != 1)) return 0;
        x >>= 1;
        cnt += 1;
    }
    return cnt - 1;
}
void solve() {
    cin >> n >> m;
    if (n % 2 == 0) cout << "NO" << '\n';
    else {
        long long now = m;
        for (int i = 1; i <= n / 2; i++) {
            long long tmp = syn(now) - now;
            if (now == tmp) break;
            now = tmp;
        }
        if (getp(now + now) % 2 == 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
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