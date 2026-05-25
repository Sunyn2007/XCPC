#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, m;
long long lca(long long a, long long b) {
    if (a % b == 0) return b;
    return lca(b, a % b);
}
void solve() {
    cin >> a >> b >> c >> m;
    long long ansa = m / a * 6, ansb = m / b * 6, ansc = m / c * 6;
    long long lcm;
    lcm = a * b / lca(a, b);
    ansa -= m / lcm * 3;
    ansb -= m / lcm * 3;
    lcm = a * c / lca(a, c);
    ansa -= m / lcm * 3;
    ansc -= m / lcm * 3;
    lcm = b * c / lca(b, c);
    ansb -= m / lcm * 3;
    ansc -= m / lcm * 3;
    lcm = a * b / lca(a, b), lcm = lcm * c / lca(lcm, c);
    ansa += m / lcm * 2;
    ansb += m / lcm * 2;
    ansc += m / lcm * 2;
    cout << ansa << ' ' << ansb << ' ' << ansc << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}