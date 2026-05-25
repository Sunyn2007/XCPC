#include <bits/stdc++.h>
using namespace std;
int a[4];
int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 3; i++) cin >> a[i];
    sort(a + 1, a + 3 + 1);
    cout << a[1] / gcd(a[1], a[3]) << '/' << a[3] / gcd(a[1], a[3]);
    return 0;
}