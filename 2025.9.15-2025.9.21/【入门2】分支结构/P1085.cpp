#include <bits/stdc++.h>
using namespace std;
const int N = 7;
int a[N + 5], b[N + 5], maxd;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 7; i++) {
        cin >> a[i] >> b[i];
        if (a[i] + b[i] > a[maxd] + b[maxd]) maxd = i;
    }
    if (a[maxd] + b[maxd] > 8) cout << maxd;
    else cout << 0;
    return 0;
}