#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int t, n, s, a[N + 5], book[3];
void cle() {
    memset(book, 0, sizeof(book));
    return ;
}
void solve() {
    int tot = 0;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i], tot += a[i], book[a[i]] += 1;
    if (tot > s) {
        for (int i = 1; i <= n; i++) 
            cout << a[i] << ' ';
    }
    else if (tot == s || tot < s - 1) 
        cout << -1;
    else {
        for (int i = 1; i <= book[0]; i++) cout << "0 ";
        for (int i = 1; i <= book[2]; i++) cout << "2 ";
        for (int i = 1; i <= book[1]; i++) cout << "1 ";
    }
    cout << '\n';
    cle();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}