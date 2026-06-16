#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n; j++) 
            cout << j << ' ';
    for (int i = 2; i <= n; i++) cout << i << ' ';
    cout << 1 << ' ';
    for (int i = 1; i <= n; i++) cout << i << ' ';
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
/*
1 2 3 4 5 1 2 3 4 5 2 3 4 5 1 1 2 3 4 5
1 2 3 4 1 2 3 4 2 3 4 1 1 2 3 4 
*/