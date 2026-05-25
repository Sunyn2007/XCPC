#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, m, h;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c >> d;
    m = c * 60 + d - a * 60 - b;
    h = m / 60;
    m %= 60;
    cout << h << ' ' << m;
    return 0;
}