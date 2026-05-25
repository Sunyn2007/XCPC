#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int calc(int x) {
    return 2 * x - 1;
}
void solve() {
    cin >> n >> k;
    if (k < n || k > calc(n)) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        while (k < calc(n)) {
            cout << n << ' ' << n << ' ';
            k -= 1, n -= 1;
        }
        if (n == 1) cout << "1 1";
        else {
            cout << "1 2 ";
            for (int i = 3; i <= n; i++)
                cout << i << ' ' << i - 2 << ' ';
            cout << n - 1 << ' ' << n;
        }
        cout << '\n';
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
/*
1 1
2 3
3 5
4 7
5 9
*/