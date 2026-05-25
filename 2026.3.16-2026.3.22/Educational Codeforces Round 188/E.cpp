#include <bits/stdc++.h>
using namespace std;
int t, n, cnt[10], mul[10] = {1, 10, 100, 1000, 10000, 100000};
string s, ans;
vector<int> book;
bool ok;
void find(vector<string> &a, int len, int x, int step) {
    if ((len - step + 1) * 9 < x) return ;
    if (step == len) {
        if (cnt[x]) {
            book.push_back(x);
            string tmp;
            for (int i = 0; i < len; i++) 
                tmp += (char)(book[i] + '0');
            a.push_back(tmp);
            book.pop_back();
        }
        return ;
    }
    for (int i = 0; i <= 9; i++) {
        if (i > x) break;
        if ((step == 1 && i == 0) || !cnt[i]) continue;
        cnt[i] -= 1, book.push_back(i);
        find(a, len, x - i, step + 1);
        cnt[i] += 1, book.pop_back();
    }
    return ;
}
void dfs(int len, int x, string num) {
    if (ok) return ;
    int tot = 0;
    for (int i = 1; i <= 9; i++)
        tot += cnt[i] * i;
    if (tot == x) {
        ok = true;
        string tmp;
        for (int i = 9; i >= 0; i--)
            for (int j = 1; j <= cnt[i]; j++)
                tmp += (char)(i + '0');
        ans = tmp + num;
        return ;
    }
    if (len <= 2) {
        for (int i = 6; i >= 2; i--) {
            if (tot < mul[i - 1]) continue;
            if (x <= i * 9) {
                vector<string> a;
                find(a, i, x, 1);
                book.clear();
                for (int j = 0; j < a.size(); j++) {
                    int tmp = 0;
                    for (int k = 0; k < a[j].size(); k++)
                        tmp = tmp * 10 + a[j][k] - '0', cnt[a[j][k] - '0'] -= 1;
                    dfs(i, tmp, a[j] + num);
                    if (ok) return ;
                    for (int k = 0; k < a[j].size(); k++)
                        cnt[a[j][k] - '0'] += 1;
                }
                a.clear();
            }
        }
    }
    return ;
}
void solve() {
    cin >> s, n = s.size(), s = ' ' + s;
    for (int i = 1; i <= n; i++) 
        cnt[s[i] - '0'] += 1;
    if (n == 1) cout << s[1] << '\n';
    else {
        for (int i = 1; i <= 9; i++)
            if (cnt[i]) {
                string tmp;
                tmp += (char)(i + '0');
                cnt[i] -= 1;
                dfs(1, i, tmp);
                if (ok) break;
                cnt[i] += 1;
            }
        cout << ans << '\n';
    }
    ok = false;
    for (int i = 0; i <= 9; i++)
        cnt[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}