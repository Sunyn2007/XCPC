#include <bits/stdc++.h>
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    int cnt = min(n, m + 1);
    cout << 1ll * cnt * (cnt - 1) / 2 - m << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve(); 
    return 0;
}