#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << (a + b > c && b == c) << '\n';
    }
    return 0;
}