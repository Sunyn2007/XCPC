#include <bits/stdc++.h>
using namespace std;
int t, a, b;
void solve() {
    cin >> a >> b;
    int cnta = 0, cntb = 0;
    for (int i = 2; i <= sqrt(a); i++)
        while (a % i == 0) a /= i, cnta += 1;
    if (a > 1) cnta += 1;
    for (int i = 2; i <= sqrt(b); i++)
        while (b % i == 0) b /= i, cntb += 1;
    if (b > 1) cntb += 1;
    if (cnta != cntb) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}