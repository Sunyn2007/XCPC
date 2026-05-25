#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int t, res;
long long n, book[20], ans[20];
bool flag;
double _abs(double x) {
    return x > 0 ? x : -x;
}
void pre() {
    book[1] = 11;
    for (int i = 2; i <= 18; i++)
        book[i] = (book[i - 1] - 1) * 10 + 1;
    return ;
}
void solve() {
    res = 0;
    cin >> n;
    for (int i = 18; i >= 1; i--) {
        long long tmp = n / book[i];
        if (tmp * book[i] == n) ans[++res] = tmp;
    }
    cout << res << '\n';
    if (res) {
        for (int i = 1; i <= res; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    while (t--) solve();
    return 0;
}