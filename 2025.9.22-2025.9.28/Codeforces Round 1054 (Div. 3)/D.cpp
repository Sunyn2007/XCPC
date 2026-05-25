#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const long long INF = 0x7fffffffffffffff;
int t, n, pos[N + 5];
string s;
int syn(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> n >> s, s = ' ' + s;
    int numa = 0, numb = 0;
    long long ans = INF;
    for (int i = 1; i <= n; i++) 
        if (s[i] == 'a') pos[++numa] = i;
    if (!numa) ans = 0;
    else {
        long long resa = 0;
        int p, l, r;
        if (numa % 2 == 0) p = pos[numa / 2], l = numa / 2 - 1, r = numa / 2;
        else p = pos[numa / 2 + 1], l = numa / 2, r = numa / 2;
        for (int i = p - l, j = 1; i <= p + r; i++, j++)
            resa += syn(i - pos[j]);
        ans = min(ans, resa);
    }
    for (int i = 1; i <= n; i++) 
        if (s[i] == 'b') pos[++numb] = i;
    if (!numb) ans = 0;
    else {
        long long resb = 0;
        int p, l, r;
        if (numb % 2 == 0) p = pos[numb / 2], l = numb / 2 - 1, r = numb / 2;
        else p = pos[numb / 2 + 1], l = numb / 2, r = numb / 2;
        for (int i = p - l, j = 1; i <= p + r; i++, j++)
            resb += syn(i - pos[j]);
        ans = min(ans, resb);
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}