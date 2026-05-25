#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
struct team{
    int id;
    long long scr;
}a[M + 5];
int t, n, m, q;
vector<int> tmp;
bool book[M + 5];
bool cmp(team a, team b) {
    if (a.scr == b.scr) return a.id < b.id;
    return a.scr > b.scr;
}
void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
        a[i].id = i, a[i].scr = 0;
    int now = 0, scr = 0;
    for (int i = 1; i <= q; i++) {
        int op, id, x;
        cin >> op;
        if (op == 1) {
            cin >> x, now = x, scr = m;
            for (int i = 0; i < tmp.size(); i++)
                book[tmp[i]] = false;
            tmp.clear();
        }
        if (op == 2) {
            cin >> id >> x;
            if (x == now && !book[id]) {
                a[id].scr += scr--;
                book[id] = true;
                tmp.push_back(id);
            }
        }
        if (op == 3) {
            cin >> id >> x;
            if (x == now && !book[id]) {
                book[id] = true;
                tmp.push_back(id);
            }
        }
    }
    for (int i = 0; i < tmp.size(); i++)
        book[tmp[i]] = false;
    tmp.clear();
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
        cout << a[i].id << ' ' << a[i].scr << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}