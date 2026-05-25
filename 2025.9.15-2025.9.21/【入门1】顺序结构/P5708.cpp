#include <bits/stdc++.h>
using namespace std;
double a, b, c, p, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c;
    p = 0.5 * (a + b + c);
    ans = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << fixed << setprecision(1) << ans;
    return 0;
}