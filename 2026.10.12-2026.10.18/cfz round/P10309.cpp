#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, MOD = 998244353;
int n, e, u[N + 5], v[N + 5], deg[N + 5], tag;
map<pair<int, int>, int> bk;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i];
        bk[make_pair(u[i], v[i])] = bk[make_pair(v[i], u[i])] = i;
        deg[u[i]] += 1, deg[v[i]] += 1;
    }
    cin >> e;
    if (n == 2) {
        cout << e << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) 
        if (deg[i] == 1) {
            for (int j = 1; j <= n; j++)
                if (bk.find(make_pair(i, j)) != bk.end()) tag = bk[make_pair(i, j)];
            break;
        }
    for (int i = 1; i < n; i++)
        cout << ((i == tag) ? (1ll * e * n % MOD) : MOD) << '\n';
    return 0;
}