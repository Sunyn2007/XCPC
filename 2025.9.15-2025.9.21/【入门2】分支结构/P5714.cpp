#include <bits/stdc++.h>
using namespace std;
double m, h, res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> m >> h;
    res = m / (h * h);
    if (res < 18.5) cout << "Underweight";
    else if (res < 24) cout << "Normal";
    else cout << res << '\n' << "Overweight";
    return 0;
}