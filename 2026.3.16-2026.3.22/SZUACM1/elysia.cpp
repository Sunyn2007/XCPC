#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], b[N], u[200005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            u[b[i]] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) u[a[i]] = 1;
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            while (u[p]) p++;
            b[i] = p;
            u[p] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) cout << b[i] << (i == n ? "" : " ");
    cout << '\n';
    return 0;
}