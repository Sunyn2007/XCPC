#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int t, n, a[N + 5];
struct syn {
    int id;
    char u, v;
};
vector<syn> s[N + 5];
int book[256];
void solve() {
    cin >> n;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= i) ok = false;
    }
    if (!ok) {
        cout << "NO" << '\n';
        return ;
    }
    s[1].push_back({1, 's', 't'});
    for (int i = 2; i <= n; i++) {
        if (i - 1 - a[i]) {
            int cnt = i - 1 - a[i];
            for (int j = 0; j < s[cnt].size(); j++) {
                char u, v;
                if (s[cnt][j].u == 's') u = 's';
                if (s[cnt][j].u == 'x') u = 't';
                if (s[cnt][j].u == 't') u = 'x';  
                if (s[cnt][j].v == 's') v = 's';
                if (s[cnt][j].v == 'x') v = 't';
                if (s[cnt][j].v == 't') v = 'x';
                s[i].push_back({s[cnt][j].id, u, v});
            }
        }
        s[i].push_back({i, 's', 't'});
        if (i - 1 - a[i]) {
            int cnt = i - 1 - a[i];
            if (cnt == i - 1) {
                for (int j = 0; j < s[i - 1].size(); j++) {
                    char u, v;
                    if (s[cnt][j].u == 's') u = 'x';
                    if (s[cnt][j].u == 'x') u = 's';
                    if (s[cnt][j].u == 't') u = 't';  
                    if (s[cnt][j].v == 's') v = 'x';
                    if (s[cnt][j].v == 'x') v = 's';
                    if (s[cnt][j].v == 't') v = 't';
                    s[i].push_back({s[cnt][j].id, u, v});
                }
            }
            else {
                for (int j = 0; j < s[cnt].size(); j++) {
                    char u, v;
                    if (s[cnt][j].u == 's') u = 'x';
                    if (s[cnt][j].u == 'x') u = 't';
                    if (s[cnt][j].u == 't') u = 's';  
                    if (s[cnt][j].v == 's') v = 'x';
                    if (s[cnt][j].v == 'x') v = 't';
                    if (s[cnt][j].v == 't') v = 's';
                    s[i].push_back({s[cnt][j].id, u, v});
                }
                for (int j = 0; j < s[i - 1].size(); j++) 
                    s[i].push_back({s[i - 1][j].id, s[i - 1][j].u, s[i - 1][j].v});
            }
        }
        else {
            for (int j = 0; j < s[i - 1].size(); j++) 
                s[i].push_back({s[i - 1][j].id, s[i - 1][j].u, s[i - 1][j].v});
        }
    }
    cout << "YES" << '\n' << s[n].size() << '\n';
    book['s'] = 1, book['x'] = 2, book['t'] = 3;
    for (int i = 0; i < s[n].size(); i++)
        cout << s[n][i].id << ' ' << book[s[n][i].u] << ' ' << book[s[n][i].v] << '\n';
    for (int i = 1; i <= n; i++) s[i].clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}