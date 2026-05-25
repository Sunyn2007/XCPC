#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    if ((n + 1) / 2 >= m) cout << "Yes";
    else cout << "No";
    return 0;
}