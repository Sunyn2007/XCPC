#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const long long INF = 5e12;
int t, n, a[N + 6];
long long c[N + 5], ans[N + 5], sum[N + 5];
char s[N + 5];
void solve() {
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    if (s[1] == '1' && a[1] != s[1]) cout << "No" << '\n';
    else {
        bool flag = false, ok = true;
        long long det;
        ans[1] = c[1], sum[1] = ans[1];
        for (int i = 2; i <= n; i++) {
            if (s[i]) {
                if (c[i] == c[i - 1]) ans[i] = a[i], sum[i] = sum[i - 1] + ans[i];
                else {
                    if (c[i] - c[i - 1] > a[i]) {
                        ok = false;
                        break;
                    }
                    else {

                    }
                }
            }
            else {
                
            }

        } 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}