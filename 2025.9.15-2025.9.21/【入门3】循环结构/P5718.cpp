#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, a[N + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << a[1];
    return 0;
}