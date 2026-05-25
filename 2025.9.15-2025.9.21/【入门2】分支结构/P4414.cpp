#include <bits/stdc++.h>
using namespace std;
string s;
int a[4];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a[1] >> a[2] >> a[3] >> s;
    sort(a + 1, a + 3 + 1);
    for (int i = 0; i < 3; i++) 
        cout << a[s[i] - 'A' + 1] << ' ';
    return 0;
}