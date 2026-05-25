#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int num = a[1], ans = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] <= num || a[i] > a[i - 1] + 1) 
            num = a[i], ans += 1;
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
1 2 3 4 5 3 2 2 2 
*/