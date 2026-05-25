#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], b[N + 5], book[N + 5], num[N + 5], cnt[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> b[i], book[b[i]] += 1;
    bool flag = true;
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (book[b[i]] % b[i] != 0) flag = false;
        if (!num[b[i]]) num[b[i]] = ++now, cnt[num[b[i]]] = 1;
        else {
            if (cnt[num[b[i]]] == b[i]) num[b[i]] = ++now, cnt[num[b[i]]] = 1;
            else cnt[num[b[i]]] += 1;
        }
        a[i] = num[b[i]];
    }
    if (!flag) cout << -1;
    else {
        for (int i = 1; i <= n; i++) 
            cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) 
        book[i] = num[i] = cnt[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}