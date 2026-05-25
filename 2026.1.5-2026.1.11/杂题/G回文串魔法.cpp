#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, a[N + 5], v[30], minv = 0x7fffffff;
long long tot, ans;
string s;
map<pair<char, char>, bool> book;
int val(int x, int y) {
    if (x == y) return 0;
    return min(minv << 1, min(v[x], v[y]));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s, s = ' ' + s;
    for (int i = 1; i <= 26; i++) cin >> v[i], minv = min(minv, v[i]);
    for (int i = 1; i <= n; i++) a[i] = s[i] - 'a' + 1;
    for (int i = 1; i <= (n >> 1); i++) {
        tot += val(a[i], a[n - i + 1]);
        book[make_pair(a[i], a[n - i + 1])] = true;
    }
    ans = tot;
    for (int i = 1; i <= 26; i++)
        for (int j = 1; j <= 26; j++)
            if (book[make_pair(i, j)])
                for (int x = 1; x <= 26; x++)
                    for (int y = 1; y <= 26; y++)
                        if (book[make_pair(x, y)])
                            ans = min(ans, tot - val(i, j) - val(x, y) + val(x, j) + val(i, y));
    if (n % 2 == 1)
        for (int i = 1; i <= (n >> 1); i++) {
            ans = min(ans, tot - val(a[i], a[n - i + 1]) + val(a[n / 2 + 1], a[n - i + 1]));
            ans = min(ans, tot - val(a[i], a[n - i + 1]) + val(a[i], a[n / 2 + 1]));
        }
    cout << ans;
    return 0;
}       