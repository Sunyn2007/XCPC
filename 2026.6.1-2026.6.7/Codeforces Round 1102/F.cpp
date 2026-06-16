#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, h[N * 2 + 5], top;
long long pre[N * 2 + 5], suf[N * 2 + 5], ans[N + 5];
struct syn {
    int v, p;
}stk[N * 2 + 5];
set<int> s;
void solve() {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) 
        cin >> h[i], h[i + n] = h[i], mx = max(mx, h[i]);
    int fst = 0, lst;
    for (int i = 1; i <= 2 * n; i++)
        if (h[i] == mx) {
            if (!fst) fst = i;
            lst = i;
            s.insert(i);
        }
    long long tmp;
    for (int i = fst; i <= 2 * n; i++) {
        if (h[i] == mx) stk[top = 1] = {mx, i}, tmp = 0;
        else {
            while (h[i] >= stk[top].v) {
                tmp -= 1ll * stk[top].v * (stk[top].p - stk[top - 1].p);
                top -= 1;
            }
            stk[++top] = {h[i], i};
            tmp += 1ll * stk[top].v * (stk[top].p - stk[top - 1].p);
        }
        suf[i] = tmp;
    }
    for (int i = lst; i >= 1; i--) {
        if (h[i] == mx) stk[top = 1] = {mx, i}, tmp = 0;
        else {
            while (h[i] >= stk[top].v) {
                tmp -= 1ll * stk[top].v * (stk[top - 1].p - stk[top].p);
                top -= 1;
            }
            stk[++top] = {h[i], i};
            tmp += 1ll * stk[top].v * (stk[top - 1].p - stk[top].p);
        }
        pre[i] = tmp;
    }
    for (int i = 1; i <= n; i++) {
        auto l = s.lower_bound(i), r = s.lower_bound(i + n);
        r--;
        ans[i] = 1ll * (*r - *l) * mx + pre[i] + suf[i + n - 1];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    s.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}