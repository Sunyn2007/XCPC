#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

int gcd(int a, int b) {
    if(b==0)return a;
    return gcd(b, a%b);
}

struct Segtree {
    struct Node {
        int g, cnt;
        Node *son[2];
        Node():g(0),cnt(0),son{NULL,NULL}{}
        void update(){
            g = 0;
            if(son[0]!=NULL)
                g = gcd(g, son[0]->g);
            if(son[1]!=NULL)
                g = gcd(g, son[1]->g);
        }
        void change(int l, int r, int x, int v) {
            if(l==r) {
                cnt += v;
                if(cnt == 0)
                    g = 0;
                else
                    g = x;
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
            this->update();
        }
    };
    int L, R;
    Node *root;
    Segtree(int l, int r):L(l),R(r) {
        root = new Node;
    }
    void change(int x, int v) {
        if(x==0)return;
        // printf("tree.change(%d, %d)\n", x, v);
        root->change(L, R, x, v);
    }
    int query_gcd() {
        return root->g;
    }
};

std::vector<std::vector<int> > ds;

void init(int n) {
    ds.resize(n+1);
    for(int i=1;i<=n;++i) {
        for(int j=1;i*j<=n;++j) {
            ds[i*j].push_back(i);
        }
    }
}

void query(int n, Segtree& tree) {
    if(tree.query_gcd() == 0) {
        printf("%d\n", n);
        return;
    }
    printf("%d\n", (int)ds[tree.query_gcd()].size());
}

void update(int x, int v, int n, Segtree& tree, std::map<int, int>&sps, std::vector<int>& a) {
    a[x] = v;
    auto it = sps.lower_bound(x);
    auto itbfr = (--it);++it;
    int len = it->second;
    int lena = x - itbfr->first - 1;
    int lenb = it->first - x;
    if(it->first!=n) {
        tree.change(len, -1);
        tree.change(lenb, 1);
    }
    tree.change(lena, 1);
    if(lena > 0)
        sps[x-1] = lena;
    if(lenb>0)
        sps[it->first] = lenb;
    else
        sps.erase(it);
    // for(auto x:sps) {
    //     printf("{%d, %d}", x.first, x.second);
    // }
    // printf("\n");
    it = sps.lower_bound(x);
    itbfr = (--it);++it;
    lenb = it->second;
    lena = itbfr->second;
    if(a[x-1]<=v && v<=a[x+1]) {
        sps.erase(x-1);
        sps[it->first] = lena + lenb + 1;
        tree.change(lena, -1);
        if(it->first != n) {
            tree.change(lenb, -1);
            tree.change(lena+lenb+1 , 1);
        }
    } else if(a[x-1]<=v) {
        sps.erase(x-1);
        sps[x] = lena+1;
        tree.change(lena, -1);
        if(x!=n)
            tree.change(lena+1, 1);
    } else if(v<=a[x+1]) {
        sps[it->first] = lenb + 1;
        if(it->first!=n) {
            tree.change(lenb, -1);
            tree.change(lenb+1, 1);
        }
    } else {
        sps[x] = 1;
        if(x!=n) {
            tree.change(1, 1);
        }
    }
    // for(auto x:sps) {
    //     printf("{%d, %d}", x.first, x.second);
    // }
    // printf("\n");
}

int main() {
    init(200000);
    int T;scanf("%d", &T);
    for(;T;--T) {
        int n, q;scanf("%d%d", &n, &q);
        std::vector<int> a(n+2);
        for(int i=1;i<=n;++i)
            scanf("%d", &a[i]);
        a[0] = INT_MAX;
        a[n+1] = INT_MIN;
        int last = INT_MAX, lap = 0;
        std::map<int, int> sps;
        Segtree tree(1, n);
        for(int i=1;i<=n+1;++i) {
            if(a[i] < last){
                sps[i-1] = i-1 - lap;
                if(i-1!=n)
                    tree.change(i-1-lap, 1);
                lap = i-1;
            }
            last = a[i];
        }
        sps[n+1] = 0;
        query(n, tree);
        for(int t=1;t<=q;++t) {
            int x, v;scanf("%d%d", &x, &v);
            update(x, v, n, tree, sps, a);
            query(n, tree);
        }
    }

    return 0;
}