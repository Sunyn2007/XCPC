#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    s[0] = s[0] - 'A' + 'a';
    s = "Of" + s;
    cout << s;
    return 0;
}