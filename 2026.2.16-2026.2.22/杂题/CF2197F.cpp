#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    vector<int> stk1, stk2, p;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') stk1.push_back(i);
        if (s[i] == ')') {
            if (!stk1.empty()) stk1.pop_back();
            else p.push_back(i);
        }
        if (s[i] == '[') stk2.push_back(i);
        if (s[i] == ']') {
            if (!stk2.empty()) stk2.pop_back();
            else p.push_back(i);
        }
    }
    for (int i = 0; i < stk1.size(); i++) p.push_back(stk1[i]);
    for (int i = 0; i < stk2.size(); i++) p.push_back(stk2[i]);
    int tmp1 = 0, tmp2 = 0, ans, fst = n, lst = 0;
    for (int i = 0; i < p.size(); i++) {
        if (s[p[i]] == '(' || s[p[i]] == '[')
            tmp1 += 1, fst = min(fst, p[i]);
        if (s[p[i]] == ')' || s[p[i]] == ']') 
            tmp2 += 1, lst = max(lst, p[i]);
    }
    if (tmp1 % 2 == 0) ans = tmp1 / 2 + tmp2 / 2;
    else if (fst < lst) ans = tmp1 / 2 + tmp2 / 2 + 1;
    else ans = tmp1 / 2 + tmp2 / 2 + 2;
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