#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const long long INF = 5e12;
int t, n, a[N + 6];
long long c[N + 5], ans[N + 5];
char s[N + 5];
void solve() {
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (s[1] == '1' && a[1] != c[1]) cout << "No" << '\n';
    else {
        bool ok = true;
        int pos = 0;
        ans[1] = c[1];
        long long sum = c[1];
        for (int i = 2; i <= n; i++) {
            if (c[i] == c[i - 1]) {
                if (s[i] == '1') {
                    ans[i] = a[i], sum += ans[i];
                    if (sum > c[i]) {
                        if (pos) ans[pos] -= (sum - c[i]), sum = c[i];
                        else {
                            ok = false;
                            break;
                        }
                    } 
                }
                else {
                    ans[i] = c[i] - sum, sum = c[i];
                    pos = i;
                }
            }
            else {
                if (c[i] < c[i - 1]) {
                    ok = false;
                    break;
                }
                if (s[i] == '1') {
                    ans[i] = a[i], sum += ans[i];
                    if (sum > c[i]) {
                        if (pos) ans[pos] -= (sum - c[i]), sum = c[i];
                        else {
                            ok = false;
                            break;
                        }
                    }
                    else if (sum < c[i]) {
                        ok = false;
                        break;
                    }
                }
                else ans[i] = c[i] - sum, sum = c[i];
                pos = 0;
            }
        }
        if (!ok) cout << "No" << '\n';
        else {
            cout << "Yes" << '\n';
            for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
            cout << '\n';
        } 
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}