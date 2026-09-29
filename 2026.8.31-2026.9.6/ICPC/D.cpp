#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, MOD = 998244353;
int n, p[N + 5], ans = 1, t1, t2, cnt[N + 5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> p[i], cnt[p[i]] += 1;
    int now = 0;
    while (now < n) {
        if (t1 == t2) {
            ans = ans * 2 % MOD;
            cnt[t1] -= 1;
            t1 += 1;
        }
        else {
            if (t1 < t2) {
                if (cnt[t1])
                    t2 += 1, cnt[t1] -= 1;
                else t1 += 1, cnt[t2] -= 1;
            }
            else {
                if (cnt[t2])
                    t1 += 1, cnt[t2] -= 1;
                else
                    t2 += 1, cnt[t1] -= 1;
            }
        }
        now += 1;
    }
    cout << ans << '\n';
    return 0;
}