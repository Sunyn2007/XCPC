#include <bits/stdc++.h>
using namespace std;
int n, m, k, book[15], ans[15], cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        book[a] += 1;
        if (book[a] == m) ans[++cnt] = a;
    }
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << ' ';
    return 0;
}