#include <bits/stdc++.h>
using namespace std;
int y, m, d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool flag;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> y >> m;
    if (y % 100 == 0 && y % 400 == 0) flag = true;
    if (y % 100 != 0 && y % 4 == 0) flag = true;
    if (flag && m == 2) cout << 29;
    else cout << d[m];
    return 0;
}