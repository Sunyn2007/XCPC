#include <bits/stdc++.h>
using namespace std;
const int N = 4000;
int t, n, a[N + 5], p[N + 5];
int resx, resy;
void mkq(int x, int y) {
    cout << '?' << ' ' << x << ' ' << y << '\n';
    cout.flush();
    cin >> resx >> resy;
    swap(a[resx], a[resy]);
    p[a[resx]] = resx, p[a[resy]] = resy;
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], p[a[i]] = i;
    for (int i = 1; i <= n / 2; i++) {
        int l = i, r = n - i + 1;
        while ((p[l] != l && p[l] != r) || (p[r] != l && p[r] != r)) {
            if (p[l] == l || p[l] == r) {
                if (p[l] == l) mkq(p[r], r);
                else mkq(p[r], l);
            }
            else {
                if (p[r] == l) mkq(p[l], r);
                else if (p[r] == r) mkq(p[l], l);
                else mkq(p[l], l);
            }
        }
        if (p[l] != l) mkq(l, r);
    }
    cout << '!' << '\n';
    cout.flush();
    return ;
}
int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}