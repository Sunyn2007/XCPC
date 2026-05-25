#include <bits/stdc++.h>
using namespace std;
int a[4];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 3; i++) cin >> a[i];
    sort(a + 1, a + 3 + 1);
    for (int i = 1; i <= 3; i++) cout << a[i] << ' ';
    return 0;
}