#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << "LR";
    int l = 2, r = n - 1, lst = n;
    bool up = a[n] > a[1] ? true : false;
    while (l <= r) {
        if (l == r) {
            cout << 'L';
            break;
        }
        if (up) {
            if (a[l] > a[lst] && a[r] > a[lst]) {
                if (a[l] > a[r]) lst = l, l += 1, cout << 'L';
                else lst = r, r -= 1, cout << 'R';
            }
            else {
                up = false;
                if (a[l] < a[lst]) lst = l, l += 1, cout << 'L';
                else lst = r, r -= 1, cout << 'R';
            }
        }
        else {
            if (a[l] < a[lst] && a[r] < a[lst]) {
                if (a[l] < a[r]) lst = l, l += 1, cout << 'L';
                else lst = r, r -= 1, cout << 'R';
            }
            else {
                up = true;
                if (a[l] > a[lst]) lst = l, l += 1, cout << 'L';
                else lst = r, r -= 1, cout << 'R';
            }
        }
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}