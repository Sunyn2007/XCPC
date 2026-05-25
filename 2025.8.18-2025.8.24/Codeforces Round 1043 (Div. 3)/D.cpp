#include <bits/stdc++.h>
using namespace std;
int t;
long long k, book[20], num[20], p[20];
void pre() {
    book[0] = 1;
    for (int i = 1; i <= 18; i++)
        book[i] = book[i - 1] * 10;
    return ;
}
void solve() {
    cin >> k;
    long long now = 1, ans = 0;
    while (true) {
        if (k > 9 * book[now - 1] * now) {
            k -= 9 * book[now - 1] * now;
            for (int i = 1; i <= 9; i++) {
                if (now == 1) ans += i;
                else ans += i * (book[now - 1] + (now - 1) * 9 * book[now - 2]);
            }
            now += 1;
        }
        else {
            long long tmp = k / now, maxn = book[now - 1] + tmp - 1;
            p[0] = 1;
            for (int i = 1; i <= now; i++) {
                num[i] = maxn % 10;
                maxn /= 10;
                p[i] = p[i - 1] * (num[i] + 1);
            }
            long long s = 1;
            for (int i = now; i >= 1; i--) {
                for (int j = 1; j <= num[i]; j++) {
                    if (j == num[i]) ans += j * s * p[i - 1];
                    
                }
                if (i == now) s *= num[i];
                else s *= (num[i] + 1);
            }
            maxn = book[now - 1] + tmp;
            k -= tmp * now;
            for (int i = 1; i <= now; i++) {
                num[i] = maxn % 10;
                maxn /= 10;
            }
            for (int i = now; i >= 1 && k >= 1; i--, k--)
                ans += num[i];
            break;
        }
    }
    cout << now << ' ' << ans << '\n';
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