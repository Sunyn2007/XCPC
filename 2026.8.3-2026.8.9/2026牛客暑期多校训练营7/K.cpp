#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, cnt[N + 5];
vector<string> s[N + 5];
int main() {
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        char ch;
        string tmp;
        while ((ch = getchar()) != '\n') {
            if (ch == ' ') s[i].push_back(tmp), tmp.clear();
            else tmp += ch;
        }
        s[i].push_back(tmp);
    }
    while (true) {
        bool fl = true;
        map<string, int> bk;
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            string tmp;
            for (int j = 0; j < cnt[i]; j++) tmp += s[i][j];
            for (int j = cnt[i]; j < s[i].size(); j++) tmp += s[i][j][0];
            if (!bk[tmp]) bk[tmp] = i;
            else fl = false, a.push_back(bk[tmp]), a.push_back(i), bk[tmp] = i;
        }
        if (fl) break;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) 
            if (i == 0 || a[i] != a[i - 1]) cnt[a[i]] += 1;
    }
    for (int i = 1; i <= n; i++) {
        string tmp;
        for (int j = 0; j < cnt[i]; j++) tmp += s[i][j];
        for (int j = cnt[i]; j < s[i].size(); j++) tmp += s[i][j][0];
        cout << tmp << '\n';
    }
    return 0;
}