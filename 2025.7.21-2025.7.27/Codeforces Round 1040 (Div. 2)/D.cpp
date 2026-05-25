#include <bits/stdc++.h>
using namespace std;
const int N = 5e3;
int t, n, p[N + 5], pos[N + 5], a[N + 5];
struct tree{
    int c[(N << 1) + 5];
    int lowbit(int x) {
        return x & (-x);
    }
    void build() {
        for (int i = 1; i <= n << 1; i++)
            c[i] = 0;
        return ;
    }
    void upd(int x) {
        for (int i = x; i <= n << 1; i += lowbit(i))
            c[i] += 1;
        return ;
    }
    int qry(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += c[i];
        return res;
    }
}tr;
int calc() {
    int res = 0;
    tr.build();
    for (int i = n; i >= 1; i--) {
        res += tr.qry(a[i]);
        tr.upd(a[i]);
    }
    return res;
}
void solve() {
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> p[i], pos[p[i]] = i, a[i] = p[i];
    ans = calc();
    for (int i = n; i >= 1; i--) {
        int x = pos[i], res = 0;
        a[x] = (n << 1) - i;
        res = calc();
        if (res < ans) ans = res;
        else a[x] = i;
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}