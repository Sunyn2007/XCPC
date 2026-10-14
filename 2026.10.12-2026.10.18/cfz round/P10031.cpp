#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
void solve() {
    cin >> n;
    if (n % 2 == 1) cout << n << '\n';
    else cout << ((n >> 1) ^ n) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}