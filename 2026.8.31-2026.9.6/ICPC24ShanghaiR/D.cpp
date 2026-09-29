#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int t, n, cnt;
string s;
struct syn {
    int p, l;
}a[N + 5];
void get(int n) {
    int p = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            if (p) a[++cnt] = {p, l};
            p = l = 0;
        }
        if (s[i] == '1') {
            if (!p) p = i, l = 1;
            else l += 1;
        }
    }
    if (p) a[++cnt] = {p, l};
    return ;
}
void push() {
    for (int i = 1; i < cnt; i++) {
        if (a[i].p + (a[i].l - 1) + (a[i].l - 1) >= a[i + 1].p - 1) {
            int blk = a[i + 1].p - 1 - (a[i].p + a[i].l - 1);
            a[i + 1].p -= a[i].l - blk, a[i + 1].l += a[i].l - blk;
        }
    }
    return ;
}
void solve() {
    cin >> n >> s, s = ' ' + s;
    if (s[n - 1] == '0' && s[n] == '0') cout << "Yes" << '\n';
    else {
        if (n <= 3) cout << "No" << '\n';
        else {
            if (s[n - 1] == '0' && s[n] == '1') {
                get(n - 2);
                push();
                if (a[cnt].l >= 2 && a[cnt].p + a[cnt].l - 1 + a[cnt].l - 2 >= n - 2) cout << "Yes" << '\n';
                else {
                    if (a[cnt].p + a[cnt].l - 1 + a[cnt].l - 1 >= n - 2) {
                        if (n <= 4) cout << "No" << '\n';
                        else {
                            if (a[cnt].p == n - 2) {
                                if (cnt == 1) cout << "No" << '\n';
                                else {
                                    if (a[cnt - 1].p + a[cnt - 1].l - 1 + a[cnt - 1].l - 1 >= n - 4) cout << "Yes" << '\n';
                                    else cout << "No" << '\n';
                                }
                            }
                            else cout << "Yes" << '\n';
                        }
                    }
                    else cout << "No" << '\n';
                }
            }
            else {
                if (s[n - 3] == '1') cout << "Yes" << '\n';
                else {
                    if (n <= 4) cout << "No" << '\n';
                    else if (s[n - 2] == '1') {
                        get(n - 4);
                        push();
                        if (a[cnt].p + a[cnt].l - 1 + a[cnt].l - 1 >= n - 4) cout << "Yes" << '\n';
                        else cout << "No" << '\n';
                    }
                    else {
                        get(n - 3);
                        push();
                        if (a[cnt].p + a[cnt].l - 1 + a[cnt].l - 1 >= n - 3) cout << "Yes" << '\n';
                        else cout << "No" << '\n';
                    }
                }
            }
        }
    }
    cnt = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}