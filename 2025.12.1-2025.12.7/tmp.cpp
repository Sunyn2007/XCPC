#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N + 5];

struct sgt {
    int d[(N << 2) + 5];
    void build(int k, int l, int r) {
        if (l == r) {
            d[k] = a[l];
            return ;
        }
        int m = (l + r) >> 1;
        build(k << 1, l, m);
        build(k << 1 | 1, m + 1, r);
        d[k] = d[k << 1] + d[k << 1 | 1];
        return ;
    }
    int query(int k, int l, int r, int s, int t) {
        if (l >= s && r <= t) return d[k];
        int m = (l + r) >> 1, res = 0;
        if (m >= s) res += query(k << 1, l, m, s, t);
        if (m < t) res += query(k << 1 | 1, m + 1, r, s, t);
        return res;
    }
};

int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

int main() {
    return 0;
}