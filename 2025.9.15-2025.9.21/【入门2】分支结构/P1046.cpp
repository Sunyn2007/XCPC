#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N + 5], h, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 10; i++) cin >> a[i];
    cin >> h;
    for (int i = 1; i <= 10; i++) 
        if (h + 30 >= a[i]) ans += 1;
    cout << ans;
    return 0;
}