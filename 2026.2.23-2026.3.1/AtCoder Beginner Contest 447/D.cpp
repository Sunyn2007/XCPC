#include <bits/stdc++.h>
using namespace std;
int n, cnt1, cnt2, ans;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s, n = s.size(), s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') cnt1 += 1;
        if (s[i] == 'B' && cnt1) cnt1 -= 1, cnt2 += 1;
        if (s[i] == 'C' && cnt2) cnt2 -= 1, ans += 1; 
    }
    cout << ans;
    return 0;
}