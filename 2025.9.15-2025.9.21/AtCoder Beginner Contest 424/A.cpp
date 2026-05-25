#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c;
    if (a == b || b == c || a == c) cout << "Yes";
    else cout << "No";
    return 0;
}