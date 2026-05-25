#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << 2 * a * b + 2 * a * c + 2 * b * c << '\n';
    }
    return 0;
}