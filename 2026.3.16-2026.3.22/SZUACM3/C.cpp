#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, a[N + 5];
long long pre[N + 5], suf[N + 5];
struct btt {
    int c[N + 5];
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int x) {
        for (int i = x; i <= N; i += lowbit(i)) 
            c[i] += 1;
        return ;
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) 
            res += c[i];
        return res;
    }
    void clear() {
        for (int i = 1; i <= N; i++)
            c[i] = 0;
        return ;
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + tr.query(N - a[i]);
        tr.update(N - a[i] + 1);
    }
    tr.clear();
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + tr.query(N - a[i]);
        tr.update(N - a[i] + 1);
    }
    long long ans = 0x7fffffffffffffff;
    for (int i = 0; i <= n; i++)
        ans = min(ans, pre[i] + suf[i + 1]);
    cout << ans;
    return 0;
}