#include <bits/stdc++.h>
using namespace std;
int t, n, res;
void mkq(int a, int b) {
    cout << a << ' ' << b << '\n';
    cout.flush();
    cin >> res;
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j + i <= n; j++) {
            mkq(j, j + i);
            if (res) return ; 
        }
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}