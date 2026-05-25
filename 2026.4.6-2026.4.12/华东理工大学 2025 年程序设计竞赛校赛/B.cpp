#include <bits/stdc++.h>
using namespace std;
int l, m2, m3;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> m2 >> m3;
    bool ok = false;
    for (int i = l; i < l + 6; i++)
        if (i % 2 == m2 && i % 3 == m3) {
            cout << i << '\n';
            ok = true;
            break;
        }
    if (!ok) cout << -1 << '\n';
    return 0;
}