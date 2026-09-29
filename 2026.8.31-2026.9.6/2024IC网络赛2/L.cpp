#include <cstdio>
#include <cmath>
typedef long long i64;

__int128_t gcd(__int128_t a, __int128_t b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

struct Frac {
    i64 x, y;
    Frac(i64 _x, i64 _y):x(_x), y(_y){}
    Frac operator + (const Frac& b) const {
        __int128_t tx = (__int128_t)x * b.y + (__int128_t)y * b.x;
        __int128_t ty = (__int128_t)y * b.y;
        __int128_t g = gcd(tx, ty);
        return Frac(tx / g, ty / g);
    }
    Frac operator - (const Frac& b) const {
        __int128_t tx = (__int128_t)x * b.y + (__int128_t)y * b.x;
        __int128_t ty = (__int128_t)y * b.y;
        __int128_t g = gcd(tx, ty);
        return Frac(tx / g, ty / g);
    }
};

i64 isq(i64 x) {
    i64 t = sqrt(x);
    if(t * t == x)
        return true;
    return false;
}

Frac solve(i64 t) {
    i64 ttt = 1ll + 8ll * t;
    if(isq(ttt)) {
        i64 c = sqrt(ttt) - 1;
        c >>= 1;
        Frac ans = Frac(t, c) + Frac(c - 1, 2);
        return ans;
    }
    i64 c = (sqrt(ttt) + 1.0) / 2.0;
    Frac ans = Frac(t, c) + Frac(c - 1, 2);
    return ans;
}

int main() {
    int n;scanf("%d", &n);
    while(n--) {
        i64 t;scanf("%lld", &t);
        auto ans = solve(t);
        printf("%lld %lld\n", ans.x, ans.y);
    }

    return 0;
}