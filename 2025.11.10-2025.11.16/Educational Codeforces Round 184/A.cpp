#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, k, a[N + 5];
void solve() {
    cin >> n >> k;
    int maxp = 0, minp = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < k) maxp = i;
        if (a[i] > k && !minp) minp = i; 
    }
    if (maxp && minp) {
        if (maxp > n - minp + 1) cout << a[maxp];
        else cout << a[minp];
    }
    else if (maxp) cout << a[maxp];
    else if (minp) cout << a[minp];
    else cout << k;
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}