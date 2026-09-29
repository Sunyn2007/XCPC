#include <bits/stdc++.h>
using namespace std;
const int NM = 1e6, S = 4e6;
int n, m, a[S];
bool tag[S], ans[S];
vector<pair<int, int> > b[NM + 5];
struct line {
    int l, r, v;
};
vector<line> l[NM + 5];
int hs(int x, int y) {
    return (x - 1) * (m + 1) + 1 + y;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}
struct bit {
    int c[NM + 5];
    int lowbit(int x) {
        return x & (-x);
    }
    void upd(int x, int y) {
        for (int i = x; i <= n; i += lowbit(i))
            c[i] += y;
        return ;
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += c[i];
        return res;
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[hs(i, j)], b[a[hs(i, j)]].push_back(make_pair(i, j));
    for (int i = 1; i <= n * m; i++) {
        if (b[i].empty()) continue;
        sort(b[i].begin(), b[i].end(), cmp);
        stack<pair<int, int> > stk, s;
        for (auto it : b[i]) {
            while (!stk.empty() && it.first >= stk.top().first) stk.pop();
            stk.push(it);
        }
        while (!stk.empty()) {
            tag[hs(stk.top().first, stk.top().second)] = true;
            s.push(stk.top());
            stk.pop();
        }
        int now = n + 1;
        for (auto it : b[i]) {
            if (tag[hs(it.first, it.second)]) {
                if (now != n + 1 && now < it.first) l[it.second + 1].push_back({now, it.first, -1});
                s.pop();
                if (s.empty()) break;
                if (now != n + 1 && now < s.top().first) l[it.second + 1].push_back({now, s.top().first, 1});
            }
            else if (it.first < now) {
                if (now != n + 1 && now < s.top().first) l[it.second].push_back({now, s.top().first, -1});
                now = it.first;
                if (now < s.top().first) l[it.second].push_back({now, s.top().first, 1});
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (auto it : l[i]) {
            tr.upd(it.l, it.v);
            tr.upd(it.r + 1, -it.v);
        }
        for (int j = 1; j <= n; j++)
            if (tr.query(j)) ans[hs(j, i)] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[hs(i, j)]) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
    return 0;
}