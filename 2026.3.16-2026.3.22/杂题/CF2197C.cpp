#include <bits/stdc++.h>
using namespace std;
int t;
long long p, q;
void solve() {
    cin >> p >> q;
    if (q <= p) cout << "Alice" << '\n';
    else {
        long long det = q - p;
        if (det * 2 <= p) cout << "Bob" << '\n';
        else cout << "Alice" << '\n';
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