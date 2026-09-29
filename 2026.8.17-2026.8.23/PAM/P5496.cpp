#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n;
string s;
struct pam {
    int id, lst, nxt[N + 5][26], fail[N + 5], len[N + 5], cnt[N + 5];
    void init() {
        len[1] = -1;
        len[2] = 0, fail[2] = 1;
        id = lst = 2;
    }
    int find(int x, int p) {
        while (s[p - 1 - len[x]] != s[p]) x = fail[x];
        return x;
    }
    void ins(char ch, int p) {
        ch -= 'a';
        int x = lst;
        x = find(x, p);
        if (!nxt[x][ch]) {
            id += 1;
            nxt[x][ch] = id;
            if (x > 1) fail[id] = nxt[find(fail[x], p)][ch];
            else fail[id] = 2;
            len[id] = len[x] + 2;
            cnt[id] = cnt[fail[id]] + 1;
        }
        x = nxt[x][ch];
        lst = x;
        return ;
    }
    void work() {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = (s[i] - 97 + ans) % 26 + 97;
            ins(s[i], i);
            ans = cnt[lst];
            cout << ans << ' ';
        }
    }
}a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s, n = s.size(), s = ' ' + s;
    a.init(), a.work();
    return 0;
}