#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
mt19937 rnd(time(0));
struct node {
    long long val;
    int ls, rs, siz, rnd;
};
struct fhq {
    int cnt = 0, root = 0, t1, t2, t3;
    node tr[N + 5];
    void clear() {
        cnt = 0, root = 0;
        return ;
    }
    int add(long long v) {
        tr[++cnt].val = v, tr[cnt].siz = 1, tr[cnt].rnd = rnd();
        tr[cnt].ls = tr[cnt].rs = 0;
        return cnt;
    }
    void pushup(int now) {
        tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1;
        return ;
    }
    void split(int now, long long k, int &x, int &y) {
        if (!now) {
            x = y = 0;
            return ;
        }
        if (tr[now].val <= k) {
            x = now;
            split(tr[now].rs, k, tr[x].rs, y);
        }
        else {
            y = now;
            split(tr[now].ls, k, x, tr[y].ls);
        }
        pushup(now);
        return ;
    }
    int merge(int x, int y) {
        if (!x || !y) return x | y;
        if (tr[x].rnd <= tr[y].rnd) {
            tr[x].rs = merge(tr[x].rs, y);
            pushup(x);
            return x;
        }
        else {
            tr[y].ls = merge(x, tr[y].ls);
            pushup(y);
            return y;
        }
    }
    void ins(long long v) {
        split(root, v, t1, t2);
        root = merge(merge(t1, add(v)), t2);
        return ;
    }
    void del(long long v) {
        split(root, v - 1, t1, t3);
        split(t3, v, t2, t3);
        root = merge(merge(t1, merge(tr[t2].ls, tr[t2].rs)), t3);
        return ;
    }
    int query(long long v) {
        int res;
        split(root, v - 1, t1, t2);
        res = tr[t1].siz + 1;
        root = merge(t1, t2);
        return res;
    }
    long long kth(int k) {
        int now = root;
        while (true) {
            if (tr[tr[now].ls].siz + 1 == k) return tr[now].val;
            else if (tr[tr[now].ls].siz + 1 < k) k -= tr[tr[now].ls].siz + 1, now = tr[now].rs;
            else now = tr[now].ls;
        }
    }
}tr1, tr2;
int t, n, a[N + 5], ans[N + 5];
long long s[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    tr1.ins(0);
    for (int i = 1; i <= n; i++) tr1.ins(s[i]), tr2.ins(i);
    for (int i = n; i >= 1; i--) {
        tr1.del(s[i]);
        tr1.split(tr1.root, s[i - 1], tr1.t1, tr1.t2);
        int rk = tr1.tr[tr1.t2].siz + 1, res = tr2.kth(rk);
        ans[i] = res;
        tr2.del(res);
        tr1.merge(tr1.t1, tr1.t2);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    tr1.clear(), tr2.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}