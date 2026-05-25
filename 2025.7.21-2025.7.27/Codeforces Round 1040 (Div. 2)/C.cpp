#include <bits/stdc++.h>
using namespace std;
const int N = 3e3;
struct data1{
    int num, a, b;
    bool operator<(const data1 &x) const {
        if (a == x.a) return b > x.b;
        return a < x.a;
    }
}a[N + 5];
int t, n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].num = i;
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + n + 1);
    int cnt = 1;
    for (int i = 2; i <= n; i++)
        if (a[i].a != a[i - 1].a) cnt += 1;
    cout << cnt << '\n';
    cout << a[1].num << ' ';
    for (int i = 2; i <= n; i++) 
        if (a[i].a != a[i - 1].a) cout << a[i].num << ' ';
    cout << "\n";
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}