#include <bits/stdc++.h>
using namespace std;
int n, now = 1;
void syn(int x) {
    if (x < 10) cout << 0 << x;
    else cout << x;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++)
            syn(now++);
        cout << '\n';
    }
    return 0;
}