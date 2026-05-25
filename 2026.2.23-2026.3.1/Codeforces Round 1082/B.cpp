#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void flt(char &x) {
    if (x == 'a') x = 'b';
    else x = 'a';
    return ;
}
void solve() {
    cin >> n >> s, s = ' ' + s;
    char l = 'a', r = (n % 2 == 1 ? 'a' : 'b');
    bool ok = true, flag = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') {
            if (flag) flag = false;
            else {
                if (l == r) flt(r);
                else flag = true;
            }
        }
        else {
            if (flag) flag = false;
            else {
                if (l == s[i]) flt(l);
                else if (r == s[i]) flt(r);
                else {
                    ok = false;
                    break;
                } 
            }
        }
    }
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
ababa
ababab
*/