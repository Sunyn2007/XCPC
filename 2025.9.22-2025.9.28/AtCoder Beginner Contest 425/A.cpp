#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) ans += i * i * i;
        else ans -= i * i * i;
    }
    cout << ans;
    return 0;
}