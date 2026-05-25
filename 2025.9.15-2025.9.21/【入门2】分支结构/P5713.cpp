#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if (n * 5 < 11 + n * 3) cout << "Local";
    else cout << "Luogu";
    return 0;
}