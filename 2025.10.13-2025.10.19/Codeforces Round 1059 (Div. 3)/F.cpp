#include <bits/stdc++.h>
using namespace std;
const int N = 3000, M = 3000;
int t, n, m, l[M + 5], r[M + 5], sum[N + 5], ans[N + 5];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        sum[l[i]] += 1, sum[r[i] + 1] -= 1;
    }
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        if (sum[i] == m) pos = i;
    }
    if (pos) {
        int num = 1;
        for (int i = 1; i <= n; i++) {
            if (i == pos) cout << 0 << ' ';
            else cout << num++ << ' ';
        }
        cout << '\n';
    }
    else {
        bool ok = false;
        for (int i = 1; i <= n - 1; i++) {
            bool flag = true;
            //1 0
            for (int j = 1; j <= m; j++)
                if (l[j] == i + 1) flag = false;
            if (flag) {
                ans[i] = 2, ans[i + 1] = 1, ok = true;
                break;
            }
            //0 1
            flag = true;
            for (int j = 1; j <= m; j++)
                if (r[j] == i) flag = false;
            if (flag) {
                ans[i] = 1, ans[i + 1] = 2, ok = true;
                break;
            }
        }
        if (!ok) {
            int num = 2;
            ans[1] = 1, ans[n] = 2;
            for (int i = 1; i <= n; i++) {
                if (ans[i]) ans[i] -= 1;
                else ans[i] = num++;
                cout << ans[i] << ' ';
            }
        }
        else {
            int num = 2;
            for (int i = 1; i <= n; i++) {
                if (ans[i]) ans[i] -= 1;
                else ans[i] = num++;
                cout << ans[i] << ' ';
            }
        }
        cout << '\n';
    }
    for (int i = 1; i <= n + 1; i++) sum[i] = ans[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}