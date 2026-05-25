#include <bits/stdc++.h>
using namespace std;
int t, k;
long long x;
void solve() {
    cin >> k >> x;
    for (int i = 1; i <= k; i++) 
        x = x << 1;
    cout << x << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}