#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5];
bool book[N + 5];
vector<int> num;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], book[a[i]] = true;
    for (int i = 1; i <= n; i++) 
        if (!book[i]) num.push_back(i);
    if (num.empty()) {
        for (int i = 1; i <= min(n, k); i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    else {
        for (int i = 0; i < min(k, (int)num.size()); i++)
            cout << num[i] << ' ';
        k -= num.size();
        if (k > 0) {
            if (num.size() == 1) {
                for (int i = 1; i <= n; i++) 
                    if (book[i] && i != a[n])
                        cout << i << ' ', k -= 1, book[i] = false;
            }
            if (k > 0) {
                for (int i = 1; i <= n; i++) {
                    if (book[i]) {
                        cout << i << ' ', k -= 1;
                        if (k <= 0) break;
                    }
                }
            }
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) book[i] = false;
    num.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
*/