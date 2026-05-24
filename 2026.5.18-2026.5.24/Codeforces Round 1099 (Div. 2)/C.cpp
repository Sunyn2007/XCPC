#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, a[N + 5];
map<int, int> book[2];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x = a[1];
    if (x == 1) book[0][1] = 0, book[0][2] = 1;
    else {
        int cnt = 0;
        while (true) {
            book[0][x] = cnt;
            if (x == 1) break;
            if (x % 2 == 1) x += 1;
            else x /= 2;
            cnt += 1;
        }
    }
    int tag = 0;
    for (int i = 2; i <= n; i++) {
        int x = a[i];
        if (x == 1) {
            if (book[tag].find(1) != book[tag].end()) book[tag ^ 1][1] = book[tag][1];
            if (book[tag].find(2) != book[tag].end()) book[tag ^ 1][2] = book[tag][2] + 1;
        }
        else {
            int cnt = 0;
            while (true) {
                if (book[tag].find(x) != book[tag].end()) book[tag ^ 1][x] = book[tag][x] + cnt;
                if (x == 1) break;
                if (x % 2 == 1) x += 1;
                else x /= 2;
                cnt += 1;
            }
        }
        book[tag].clear();
        tag ^= 1;
    }
    int ans = INT_MAX;
    for (auto it = book[tag].begin(); it != book[tag].end(); it++) 
        ans = min(ans, (*it).second);
    cout << ans << '\n';
    book[tag].clear();
    return ;    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}