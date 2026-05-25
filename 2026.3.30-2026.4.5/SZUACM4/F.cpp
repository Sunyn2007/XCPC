#include <bits/stdc++.h>
using namespace std;
const int N = 1000, M = 1000;
int n, m, k, p, r[N + 5], c[M + 5], fac[N + 5], inv[N + 5];
void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = 1ll * fac[i - 1] * i % p;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    
    return 0;
}