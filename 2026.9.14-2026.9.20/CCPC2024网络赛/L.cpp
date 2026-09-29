#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string s[505];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] = ' ' + s[i];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (s[i][j] == 'c' && s[i][j + 1] == 'c' && s[i + 1][j] == 'p' && s[i + 1][j + 1] == 'c')
                ans += 1;
    cout << ans;
    return 0;
}