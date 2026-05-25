#include <bits/stdc++.h>
using namespace std;
const int N = 2e4;
int t, n, res, tmp[N + 5];
bool pos[N + 5], num[N + 5];
void mkq(int i, int x) {
    cout << '?' << ' ' << i << ' ' << x << '\n';
    cout.flush();
    cin >> res;
    return ;
}
void solve() {
    cin >> n;
    int tot = 0, now = 1;
    while (tot < n - 1) {
        int tot0 = 0, tot1 = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++)
            if (!num[i]) {
                if ((i >> now - 1) & 1) tot1 += 1;
                else tot0 += 1;
            }
        for (int i = 1; i < n; i++)
            if (!pos[i]) {
                mkq(i, 1 << now - 1);
                tmp[i] = res;
                if (res == 1) cnt1 += 1;
                else cnt0 += 1;
            }
        if (cnt1 < tot1) {
            for (int i = 1; i <= n; i++)
                if (!num[i] && !((i >> now - 1) & 1)) 
                    num[i] = true, tot += 1;
            for (int i = 1; i < n; i++)
                if (!pos[i] && tmp[i] == 0) 
                    pos[i] = true;
        }
        if (cnt0 < tot0) {
            for (int i = 1; i <= n; i++)
                if (!num[i] && ((i >> now - 1) & 1)) 
                    num[i] = true, tot += 1;
            for (int i = 1; i < n; i++)
                if (!pos[i] && tmp[i] == 1) 
                    pos[i] = true;
        }
        now += 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            cout << '!' << ' ' << i << '\n';
            cout.flush();
        }
        else num[i] = false;
        if (i < n) pos[i] = false;
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