#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, a[N + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) cnt0 += 1;
        else cnt1 += 1;
    }
    sort(a + 1, a + n + 1);
    if (!cnt1) cout << a[n] / 2;
    else {
        if (cnt1 % 2 == 0) {
            if (a[n] % 2 == 0) cout << a[n] / 2;
            else cout << (a[n] - 1) / 2;
        }
        else {
            if (a[n] % 2 == 0) cout << a[n] / 2;
            else cout << a[n] / 2 + 1;
        }
    }
    return 0;
}