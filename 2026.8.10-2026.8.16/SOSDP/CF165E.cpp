#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, a[N + 5], s[1 << 22];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]] = a[i];
    }
    for (int i = 1; i <= 22; i++)
        for (int msk = 0; msk < (1 << 22); msk++)
            if (((msk >> i - 1) & 1) && (s[msk ^ (1 << i - 1)]))
                s[msk] = s[msk ^ (1 << i - 1)];
    for (int i = 1; i <= n; i++) {
        if (s[a[i] ^ ((1 << 22) - 1)]) cout << s[a[i] ^ ((1 << 22) - 1)] << ' ';
        else cout << -1 << ' ';
    }
    return 0;
}