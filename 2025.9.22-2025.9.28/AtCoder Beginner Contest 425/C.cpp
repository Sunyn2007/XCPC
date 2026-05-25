#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, q, a[(N << 1) + 5];
long long sum[(N << 1) + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], a[i + n] = a[i];
    for (int i = 1; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + a[i];
    int now = 0;
    for (int i = 1; i <= q; i++) {
        int opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            now = (now + x) % n;
        }
        if (opt == 2) {
            cin >> x >> y;
            cout << sum[now + y] - sum[now + x - 1] << '\n';
        }
    }
    return 0;
}