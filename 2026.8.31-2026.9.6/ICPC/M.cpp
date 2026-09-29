#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, bool> bk1, bk2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        bk1[s] = true;
    }
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (!bk1[s]) cout << "WRONG" << '\n';
        else if (!bk2[s]) cout << "OK" << '\n', bk2[s] = true;
        else cout << "REPEAT" << '\n';
    }
    return 0;
}