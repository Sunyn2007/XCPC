#include <cstdio>
#include <climits>
#include <vector>

typedef long long int64;

struct Segtree {
    struct Node {
        int64 mx;
        Node *son[2];
        void pushup() {
            mx = LLONG_MIN;
            if(son[0])
                mx = std::max(mx, son[0]->mx);
            if(son[1])
                mx = std::max(mx, son[1]->mx);
        }
        void change(int l, int r, int x, int v) {
            if(l == r) {
                mx = v;
                return;
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0]==NULL)
                    son[0] = new Node;
                son[0]->change(l, mid, x, v);
            } else {
                if(son[1]==NULL)
                    son[1] = new Node;
                son[1]->change(mid+1, r, x, v);
            }
            pushup();
        }
        int64 max(int l, int r, int ql, int qr) {
            if(l<=ql&&qr<=r) {
                return this->mx;
            }
            int mid = ((l+r)>>1);
            int64 ans = LLONG_MIN;
            if(ql<=mid) {
                ans = std::max(ans, son[0]->max(l, mid, ql, qr));
            }
            if(qr>mid) {
                ans = std::max(ans, son[1]->max(mid+1, r, ql, qr));
            }
        }
    };
    Node *root;
    int L, R;
    Segtree(int l, int r) {
        L = l, R = r;
        root = new Node;
    }
    void change(int x, int v) {
        root->change(L, R, x, v);
    }
    int64 max(int l, int r) {
        return root->max(L, R, l, r);
    }
};

int main() {
    int n, m;scanf("%d%d", &n, &m);
    std::vector<int64> s(n+1);
    for(int i=0;i<=n-m;++i) {
        scanf("%lld", &s[i]);
    }
    std::vector<std::vector<int64> > d(m);
    for(int i=0;i<m;++i)
        d[i].push_back(0);
    for(int i=m;i<n;++i) {
        int64 last = d[i%m].back();
        d[i%m].push_back(last + s[i-m+1] - s[i-m]);
    }
    std::vector<Segtree> tree;
    for(int i=0;i<m;++i) {
        tree.emplace_back(0, d[i].size());
        for(int j=0;j<(int)d[i].size();++j) {
            tree[i].change(j, d[i][j]);
        }
    }
    int q;scanf("%d", &q);
    while(q--) {
        int l, r;scanf("%d%d", &l, &r);
        int len = r - l + 1;
        if(len < m) {
            printf("unbounded\n");
            continue;
        }
        
    }



    return 0;
}