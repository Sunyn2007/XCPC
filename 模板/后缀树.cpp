#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
struct syn {
    int id, x, y;
}t1[N + 5], t2[N + 5];
int n, sa[N + 5], rk[N + 5], h[N + 5], cnt[N + 5], len, v, num;
int fa[N * 2 + 5], l[N * 2 + 5], pos[N * 2 + 5], sz[N * 2 + 5], st[N * 2 + 5], top, tot;
vector<int> ch[N * 2 + 5];
char s[N + 5];
void dfs(int u) {
    for (int v : ch[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) 
        rk[i] = s[i], v = max(v, (int)s[i]);
    for (len = 1; len <= n; len <<= 1) {
        for (int i = 1; i <= n; i++)
            t1[i].id = i, t1[i].x = rk[i], t1[i].y = (i + len > n ? 0 : rk[i + len]);
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t1[i].y] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t2[cnt[t1[i].y]--] = t1[i];
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t1[i].x] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t1[cnt[t2[i].x]--] = t2[i];
        num = 0;
        for (int i = 1; i <= n; i++) {
            if (i == 1 || t1[i].x != t1[i - 1].x || t1[i].y != t1[i - 1].y) num += 1;
            rk[t1[i].id] = num;
        }
        if (num == n) break;
        else v = num;
    }
    for (int i = 1; i <= n; i++) sa[rk[i]] = i;
    len = 0;
    for (int i = 1; i <= n; i++) {
        if (rk[i] == 1) len = 0;
        else {
            if (len) len -= 1;
            int j = sa[rk[i] - 1];
            while (i + len <= n && j + len <= n && s[i + len] == s[j + len]) len += 1;
        }
        h[rk[i]] = len;
    }
    tot = top = st[1] = 1;
    for (int i = 1; i <= n; i++) {
        int last = 0;
        while (top > 1 && l[st[top]] > h[i]) {
            last = st[top];
            top -= 1;
        }
        if (top >= 1 && l[st[top]] < h[i]) {
            tot += 1;
            l[tot] = h[i], fa[tot] = st[top], pos[tot] = sa[i];
            if (last) fa[last] = tot;
            top += 1, st[top] = tot;
        }
        tot += 1;
        l[tot] = n - sa[i] + 1, fa[tot] = st[top], pos[tot] = sa[i], sz[tot] = 1;
        top += 1, st[top] = tot;
    }
    for (int i = 2; i <= tot; i++) ch[fa[i]].push_back(i);
    dfs(1);
    return 0;
}