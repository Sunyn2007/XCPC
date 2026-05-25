#include <bits/stdc++.h>
using namespace std;
string s;
int a[11], cnt, res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
       if (s[i] >= '0' && s[i] <= '9') a[++cnt] = s[i] - '0';
    for (int i = 1; i <= 9; i++) res += a[i] * i;
    res %= 11;
    if (res == a[10] || (res == 10 && s[s.size() - 1] == 'X')) cout << "Right";
    else {
        for (int i = 0; i < s.size() - 1; i++) cout << s[i];
        if (res <= 9) cout << res;
        else cout << 'X';
    }
    return 0;
}