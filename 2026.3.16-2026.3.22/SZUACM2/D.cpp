#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, tot[26], cnt[26];
string s;
void solve() {
    cin >> s, n = s.size(), s = ' ' + s;
    int l = 1, r = n / 2;
    while (l <= n / 2 && s[l] == s[n - l + 1]) l += 1;
    while (r >= 1 && s[r] == s[n - r + 1]) r -= 1;
    if (l > n / 2) {
        cout << 0 << '\n';
        return ;
    }
    memset(tot, 0, sizeof(tot)), memset(cnt, 0, sizeof(cnt));
    for (int i = l; i <= r; i++) 
        cnt[s[i] - 'a'] += 1, tot[s[i] - 'a'] += 1;
    for (int i = n - r + 1; i <= n - l + 1; i++)
        tot[s[i] - 'a'] += 1;
    bool flag = true;
    for (int i = 0; i < 26; i++) 
        if (cnt[i] != tot[i] - cnt[i]) flag = false;
    if (flag) {
        cout << r - l + 1 << '\n';
        return ;
    }
    int ans = n - (l - 1) * 2;
    memset(tot, 0, sizeof(tot));
    for (int i = l; i <= n - l + 1; i++)
        tot[s[i] - 'a'] += 1;
    memset(cnt, 0, sizeof(cnt));
    for (int i = l; i <= n - l + 1; i++) {
        cnt[s[i] - 'a'] += 1;
        bool flag = true;
        for (int j = 0; j < 26; j++)
            if (tot[j] - cnt[j] > cnt[j]) flag = false;
        if (flag) {
            ans = min(ans, i - l + 1);
            break;
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = n - l + 1; i >= l; i--) {
        cnt[s[i] - 'a'] += 1;
        bool flag = true;
        for (int j = 0; j < 26; j++)
            if (tot[j] - cnt[j] > cnt[j]) flag = false;
        if (flag) {
            ans = min(ans, n - l + 1 - i + 1);
            break;
        }
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}