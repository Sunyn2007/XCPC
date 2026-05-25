#include <bits/stdc++.h>
using namespace std;
int n, w[4], c[4], ans = 0x7fffffff;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 3; i++) {
        cin >> w[i] >> c[i];
        if (n % w[i] == 0) ans = min(ans, n / w[i] * c[i]);
        else ans = min(ans, (n / w[i] + 1) * c[i]);
    }
    cout << ans;
    return 0;
}