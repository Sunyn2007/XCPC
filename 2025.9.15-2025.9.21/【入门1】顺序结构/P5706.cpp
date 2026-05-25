#include <bits/stdc++.h>
using namespace std;
double t;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t >> n;
    cout << fixed << setprecision(3) << t / n << '\n';
    cout << 2 * n << '\n';
    return 0;
}