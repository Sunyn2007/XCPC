#include <cstdio>
typedef long long i64;

bool check(i64 l, i64 r) {
    if(2ll * l > r) {
        i64 len = r - l + 1;
        if(len&1)return true;
        else return false;
    }
    if(l & 1)
        return true;
    if(!check(l + 1, r))
        return true;
    return false;
}

void solve() {
    i64 l, r;scanf("%lld%lld", &l, &r);
    if(check(l, r))
        printf("Alice\n");
    else
        printf("Bob\n");
}

int main() {
    int T;scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}