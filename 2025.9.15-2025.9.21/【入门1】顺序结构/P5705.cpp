#include <bits/stdc++.h>
using namespace std;
double a;
int b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a;
    b = a * 10;
    cout << b % 10 << '.', b /= 10;
    while (b) {
        cout << b % 10;
        b /= 10;
    }
    return 0;
}