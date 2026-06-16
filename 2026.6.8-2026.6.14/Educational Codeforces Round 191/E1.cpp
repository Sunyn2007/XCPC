#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int t, n, len;
char s[15][N + 5];
int dp[1 << 11];
void solve() {
    cin >> n;
    while (n) {
        len += 1;
        n >>= 1;
    }
    cout << len << '\n';
    for (int i = 1; i <= len; i++) cin >> (s[i] + 1);
    dp[0] = 1;
    for (int i = 0; i < (1 << len); i++) {
        for (int j = 1; j <= len; j++) 
            if ()
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