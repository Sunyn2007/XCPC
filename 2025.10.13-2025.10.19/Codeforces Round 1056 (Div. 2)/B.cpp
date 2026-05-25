#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, k;
char ch[N + 5][N + 5];
void solve() {
    cin >> n >> k, k = n * n - k;
    if (k == 0) {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << 'D';
            cout << '\n';
        }
    }
    else if (k == 1) cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        ch[1][1] = 'R';
        int r = 1;
        for (int i = 2; i <= min(n, k); i++)
            ch[r][i] = 'L';
        k -= n, r += 1;
        while (k > 0) {
            for (int i = 1; i <= min(n, k); i++)
                ch[r][i] = 'U';
            k -= n, r += 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!ch[i][j]) ch[i][j] = 'D';
                cout << ch[i][j];
            }
            cout << '\n';
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ch[i][j] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}