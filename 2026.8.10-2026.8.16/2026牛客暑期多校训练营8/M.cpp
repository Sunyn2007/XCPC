#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, m, tr[N + 5][26], tot, fa[N + 5], son[N + 5], cnt, ans;
bool tag[N + 5];
queue<int> bk[N + 5];
priority_queue<pair<int, int> > q;
string s[N + 5];
void ins(string s, int id) {
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (!tr[now][ch]) tr[now][ch] = ++tot, fa[tr[now][ch]] = now;
        now = tr[now][ch];
        bk[now].push(id);
    }
    return ;
}
void upd(string s) {
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (!tag[tr[now][ch]]) ans += 1, cnt += 1, tag[tr[now][ch]] = true, son[now] += 1;
        now = tr[now][ch];
        bk[now].pop();
    }
    if (!son[now]) q.push(make_pair(bk[now].front(), now));
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ins(s[i], i);
    }
    for (int i = 1; i <= tot; i++)
        bk[i].push(n + 1);
    for (int i = 1; i <= n; i++) {
        upd(s[i]);
        while (cnt > m) {
            int x = q.top().first, y = q.top().second;
            q.pop();
            if (son[y]) continue;
            if (x != bk[y].front()) {
                q.push(make_pair(bk[y].front(), y));
                continue;
            }
            cnt -= 1, tag[y] = false, son[fa[y]] -= 1;
            if (fa[y] && !son[fa[y]]) q.push(make_pair(bk[fa[y]].front(), fa[y]));
        }
    }
    cout << ans << '\n';
    return 0;
}