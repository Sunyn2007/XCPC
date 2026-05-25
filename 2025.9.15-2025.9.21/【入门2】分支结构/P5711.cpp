#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if (n % 100 == 0) {
        if (n % 400 == 0) cout << 1;
        else cout << 0;
    }
    else {
        if (n % 4 == 0) cout << 1;
        else cout << 0;
    }
    return 0;
}