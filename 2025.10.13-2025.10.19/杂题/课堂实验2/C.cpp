#include <bits/stdc++.h>
using namespace std;
double a, b, c, det, x1, x2;
int main() {
    cin >> a >> b >> c;
    det = b * b - 4 * a * c;
    x1 = (-b + sqrt(det)) / (2 * a);
    x2 = (-b - sqrt(det)) / (2 * a);
    cout << fixed << setprecision(2) << "x1=" << x1 << ' ' << "x2=" << x2;
    return 0;
}