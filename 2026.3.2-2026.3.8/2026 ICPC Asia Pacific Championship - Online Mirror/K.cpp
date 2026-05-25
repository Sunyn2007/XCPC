#include <bits/stdc++.h>
using namespace std;
int t, n, book[10];
string s;
bool check() {
    int h1 = -1, h2 = -1, m1 = -1, m2 = -1;
    for (int i = 0; i <= 1; i++)
        if (book[i]) {
            book[i] -= 1, h1 = i;
            break;
        }
    if (h1 == -1) return false;
    if (h1 == 1)
        for (int i = 1; i >= 0; i--)
            if (book[i]) {
                book[i] -= 1, h2 = i;
                break;
            }
    if (h1 == 0)
        for (int i = 9; i >= 0; i--)
            if (book[i]) {
                book[i] -= 1, h2 = i;
                break;
            }
    if (h2 == -1) return false;
    for (int i = 5; i >= 0; i--) 
        if (book[i]) {
            book[i] -= 1, m1 = i;
            break;
        }
    if (m1 == -1) return false;
    for (int i = 9; i >= 0; i--) 
        if (book[i]) {
            book[i] -= 1, m2 = i;
            break;
        }
    if (m2 == -1) return false;
    return true;
}
void solve() {
    for (int i = 0; i <= 9; i++) book[i] = 0;
    cin >> n >> s, s = ' ' + s;
    for (int i = 1; i <= n; i++) 
        book[s[i] - '0'] += 1;
    int ans = 0;
    while (check()) ans += 1;
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}