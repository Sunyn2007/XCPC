#include <bits/stdc++.h>
using namespace std;
int m, t, s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> m >> t >> s;
    if (t == 0) cout << 0;
    else {
        if (s % t == 0) cout << max(0, m - s / t);
        else cout << max(0, m - (s / t + 1));
    }
    return 0;
}