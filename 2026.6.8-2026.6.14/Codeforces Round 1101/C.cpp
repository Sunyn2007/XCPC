#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, x, y;
char s[N + 5];
void solve() {
    cin >> n >> x >> y >> (s + 1);
    int tb = 0, a = 0, tot = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'I' && tb < x) tb += 1, tot += 1;
        if (s[i] == 'E') {
            if (tot < 1ll * tb * y) tot += 1;
            else if (a && tb < x)
                a -= 1, tb += 1, tot += 1;
        }
        if (s[i] == 'A') {
            if (tot < 1ll * tb * y) tot += 1, a += 1;
            else if (tb < x) tb += 1, tot += 1;
        }
    }
    cout << tot << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}