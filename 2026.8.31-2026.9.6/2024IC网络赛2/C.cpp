#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int n, s[N + 5], a[N + 5], b[N + 5], nxt[N + 5], sum, cnt[N + 5];
long long ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x >> a[i] >> b[i];
        s[i] = (x + ans) % n;
        if (i == 1) nxt[i] = cnt[i] = 0;
        else {
            int j = nxt[i - 1];
            if (s[j + 1] == s[i] && cnt[i - 1] == cnt[j + 1]) {
                nxt[i] = j + 1, cnt[i] = cnt[nxt[i]] + 1;
                sum += b[i];
            }
            else {
                sum = 0;
                while (j && s[j + 1] != s[i]) j = nxt[j];
                if (s[j + 1] == s[i]) j += 1;
                nxt[i] = j;
                if (j) cnt[i] = cnt[nxt[i]] + 1;
                while (j) sum += b[i - j + 1], j = nxt[j];
            }
            ans += 1ll * a[i] * sum;
        }
        ans += a[i] * b[1];
        cout << ans << '\n';
    }
    return 0;
}