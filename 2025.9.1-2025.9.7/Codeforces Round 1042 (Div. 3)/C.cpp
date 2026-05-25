#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5], b[N + 5];
map<int, int> book;
void solve() {
    bool flag = true;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], a[i] %= k;
    for (int i = 1; i <= n; i++) 
        cin >> b[i], b[i] %= k, book[b[i]] += 1;
    for (int i = 1; i <= n; i++) {
        if (book[a[i]]) book[a[i]] -= 1;
        else if (book[k - a[i]]) book[k - a[i]] -= 1;
        else {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << '\n';
    book.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}