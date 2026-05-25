#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
mt19937 rnd(time(0));
struct node {
    int val, ls, rs, siz, rnd;
};
struct fhq {
    int cnt = 0, root = 0, t1, t2, t3;
    node tr[N + 5];
    int add(int v) {
        tr[++cnt].val = v, tr[cnt].siz = 1, tr[cnt].rnd = rnd();
        tr[cnt].ls = tr[cnt].rs = 0;
        return cnt;
    }
    void pushup(int now) {
        tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1;
        return ;
    }
    void split(int now, int k, int &x, int &y) {
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
    void ins(int v) {
        split(root, v, t1, t2);
        root = merge(merge(t1, add(v)), t2);
        return ;
    }
    void del(int v) {
        split(root, v - 1, t1, t3);
        split(t3, v, t2, t3);
        root = merge(merge(t1, merge(tr[t2].ls, tr[t2].rs)), t3);
        return ;
    }
    int query(int v) {
        int res;
        split(root, v - 1, t1, t2);
        res = tr[t1].siz + 1;
        root = merge(t1, t2);
        return res;
    }
    int kth(int k) {
        int now = root;
        while (true) {
            if (tr[tr[now].ls].siz + 1 == k) return tr[now].val;
            else if (tr[tr[now].ls].siz + 1 < k) k -= tr[tr[now].ls].siz + 1, now = tr[now].rs;
            else now = tr[now].ls;
        }
    }
    int gpre(int x) {
        split(root, x - 1, t1, t2);
        int now = t1, res;
        while (tr[now].rs) now = tr[now].rs;
        res = tr[now].val;
        root = merge(t1, t2);
        return res;
    }
    int gsuf(int x) {
        split(root, x, t1, t2);
        int now = t2, res;
        while (tr[now].ls) now = tr[now].ls;
        res = tr[now].val;
        root = merge(t1, t2);
        return res;
    }
}s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}