#include <bits/stdc++.h>
using namespace std;
const int N = 5e3;
int t, n, k, stk1[N + 5], top1, stk2[N + 5], top2;
char s[N + 5];
bool ans[N + 5];
void solve() {
    cin >> n >> k >> (s + 1);
    top1 = top2 = 0;
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') stk1[++top1] = i;
        else {
            if (top1 == top2) {
                lst = i;
                if (top1 && top2) {
                    if (k) k -= 1, ans[stk1[top1--]] = true, top2 -= 1;
                    else break;
                }
            }
            else stk2[++top2] = i;
        }
    }
    while (top2 && k) {
        if (stk2[top2] > lst) ans[stk2[top2]] = true;
        else ans[stk1[top2]] = true;
        top2 -= 1, k -= 1;
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cout << 1;
        else cout << 0;
        ans[i] = false;
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}