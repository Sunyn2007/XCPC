#include <bits/stdc++.h>
using namespace std;
int t, n;
long long book[20], ans;
void pre() {
    book[0] = 1;
    for (int i = 1; i <= 19; i++) 
        book[i] = book[i - 1] * 3;
    return ;
}
void solve() {
    ans = 0;
    cin >> n;
    for (int i = 18; i >= 0; i--) {
        while (n >= book[i]) {
            n -= book[i];
            ans += book[i + 1] + i * book[i - 1];
        }
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    while (t--) solve();
    return 0;
}