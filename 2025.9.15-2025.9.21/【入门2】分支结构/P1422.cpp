#include <bits/stdc++.h>
using namespace std;
const double C1 = 0.4463, C2 = 0.4663, C3 = 0.5663;
int n;
double ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if (n <= 150) ans = n * C1;
    else if (n <= 400) ans = 150 * C1 + (n - 150) * C2;
    else ans = 150* C1 + 250 * C2 + (n - 400) * C3;
    cout << fixed << setprecision(1) << ans;
    return 0;
}