#include <bits/stdc++.h>
using namespace std;
double h, r, v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> h >> r;
    v = 3.14 * r * r * h;
    cout << (int)ceil(20000.0 / v);
    return 0;
}