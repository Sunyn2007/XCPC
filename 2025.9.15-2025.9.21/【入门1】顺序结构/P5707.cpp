#include <bits/stdc++.h>
using namespace std;
int s, v, t, h, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s >> v;
    if (s % v == 0) t = s / v;
    else t = s / v + 1;
    h = 8, m = 0;
    while (t >= 60)
        t -= 60, h -= 1;
    m -= t, m -= 10;
    while (m < 0) m += 60, h -= 1;
    if (h < 0) h += 24;
    if (h < 10) cout << '0' << h;
    else cout << h;
    cout << ':';
    if (m < 10) cout << '0' << m;
    else cout << m;
    return 0;
}