#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

i64 highbit(i64 x) {
    i64 ans = (1ll << 60);
    while(ans > x)
        ans >>= 1;
    return ans;
}

struct Base {
    i64 bit;
    veci64 p;
    Base(i64 n = 60) : bit(n), p(n + 1){}
    void insert(i64 x) {
        for (i64 i = bit; i >= 0; --i) {
            if((x >> i) & 1ll) {
                if(!p[i]) {
                    p[i] = x;
                    break;
                }
                x ^= p[i];
            }
        }
    }
};

i64 rest(i64 val, const Base& base) {
    for (int i = base.bit; i >= 0; --i) {
        if((val >> i) & 1ll)
            val ^= base.p[i];
    }
    return val;
}

void solve() {
    int n;scanf("%d", &n);
    veci64 a(n + 2), b(n + 2), c(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i) {
        c[i] = (a[i] ^ b[i]);
    }
    i64 va = 0, vb = 0;
    for (int i = 1; i <= n; ++i)
        va ^= a[i];
    for (int i = 1; i <= n; ++i)
        vb ^= b[i];
    Base base;
    for (int i = 1; i <= n; ++i) {
        base.insert(c[i]);
    }
    i64 tt = highbit(va ^ vb);
    if(tt == 0) {
        for (int i = base.bit; i >= 0; --i) {
            if((va >> i) & 1ll) {
                va ^= base.p[i];
                vb ^= base.p[i];
            }
        }
        printf("%lld\n", va);
    } else {
        int tp = 0;
        while((1ll << tp) < tt)
            ++tp;
        for (int i = base.bit; i >= 0; --i) {
            if((1ll << i) <= tt)
                break;
            if((va >> i) & 1ll) {
                va ^= base.p[i];
                vb ^= base.p[i];
            }
        }
        i64 ans = 0;
        ans |= tt;
        ans |= (va & ~(tt | (tt - 1)));
        i64 mnv = std::min(va, vb);
        i64 mxv = std::max(va, vb);
        if(base.p[tp]) {
            ans |= std::min(rest(mxv & (tt - 1), base), rest((mnv ^ base.p[tp]) & (tt - 1), base));
        } else {
            ans |= rest(mxv & (tt - 1), base);
        }
        printf("%lld\n", ans);
    }
}

int main() {
    int T;scanf("%d", &T);
    while(T--)solve();
    return 0;
}