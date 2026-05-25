#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;
void solve() {
    cin >> n >> a >> b;
    if (a <= b) {
        if (b % 2 == n % 2) cout << "Yes" << "\n";
        else cout << "No" << '\n';
    }
    else {
        if (a % 2 == n % 2 && b % 2 == n % 2) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}