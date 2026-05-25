#include <bits/stdc++.h>
using namespace std;
int x;
bool flag1, flag2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> x;
    if (x % 2 == 0) flag1 = true;
    if (x > 4 && x <= 12) flag2 = true;
    if (flag1 && flag2) cout << 1 << ' ';
    else cout << 0 << ' ';
    if (flag1 || flag2) cout << 1 << ' ';
    else cout << 0 << ' ';
    if ((flag1 && !flag2) || (!flag1 && flag2)) cout << 1 << ' ';
    else cout << 0 << ' ';
    if (!flag1 && !flag2) cout << 1 << ' ';
    else cout << 0 << ' ';
    return 0;
}