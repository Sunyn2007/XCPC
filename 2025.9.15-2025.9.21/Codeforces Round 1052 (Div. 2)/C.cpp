#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, p[N + 5];
string s;
void syn(int x, int y) {
    for (int i = x, j = y; i <= y; i++, j--) 
        p[i] = j;
    return ;
}
void solve() {
    cin >> n;
    cin >> s, s = ' ' + s + ' ';
    bool flag = true;
    for (int i = 1, j; i <= n; i = j + 1) {
        j = i;
        if (s[i] == '0') {
            while (j + 1 <= n && s[j + 1] == '0') j += 1;
            int len = j - i + 1;
            if (len == 1) flag = false;
            syn(i, j);
        }
        else p[i] = i;
    }
    if (!flag) cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) cout << p[i] << ' ';
        cout << '\n';
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