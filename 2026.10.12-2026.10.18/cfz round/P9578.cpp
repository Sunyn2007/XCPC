#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, p[N + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 2; i <= n / 2; i += 2) swap(p[i], p[n - i + 1]);
    for (int i = 1; i <= n; i++) cout << p[i] << ' ';
    return 0;
}