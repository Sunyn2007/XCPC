#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = 100;
int n, m, l[N + 5], x[N + 5][M + 5], ans[N + 5];
bool book[M + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        bool flag = false;
        for (int j = 1; j <= l[i]; j++) {
            cin >> x[i][j];
            if (!flag && !book[x[i][j]])
                ans[i] = x[i][j], flag = true, book[x[i][j]] = true;
        }
        if (!flag) ans[i] = 0;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}