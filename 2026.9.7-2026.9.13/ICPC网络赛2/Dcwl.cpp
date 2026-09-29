#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

constexpr i64 MOD = 998244353;

struct Range {
    int l, r;
    Range():l(),r(){}
    Range(int _l, int _r):l(_l), r(_r){}
};

bool operator < (const Range& a, const Range& b) {
    int lena = a.r - a.l + 1;
    int lenb = b.r - b.l + 1;
    if(lena == lenb)
        return a.l > b.l;
    return lena < lenb;
}

void insert(int l, int r, std::set<std::pair<int, int> >& set, i64 &totlen) {
    auto it = set.lower_bound({l, 0});
    if(it != set.begin()) {
        --it;
        if(it->second >= l - 1)
            l = it->first;
    }
    it = set.lower_bound({r + 2, 0});
    if(it != set.begin()) {
        --it;
        if(it->second >= r)
            r = it->second;
    }
    std::vector<std::pair<int, int> > del;
    for(it = set.lower_bound({l, 0}); it != set.end(); ++it) {
        if(it->first > r)
            break;
        del.emplace_back(*it);
    }
    for(auto [cl, cr] : del) {
        totlen -= (cr - cl + 1);
        set.erase({cl, cr});
    }
    set.insert({l, r});
    totlen += r - l + 1;
}

i64 solve() {
    int nt, Q;scanf("%d%d", &nt, &Q);
    int tot = (1<<(nt + 1)) - 1;
    veci ll(tot + 10);
    veci rr(tot + 10);
    ll[1] = 1;
    rr[1] = (1 << nt);
    for (int x = 1; x <= tot; ++x) {
        int ls = x * 2;
        int rs = x * 2 + 1;
        if(ls > tot)
            continue;
        int mid = ((ll[x] + rr[x]) >> 1);
        ll[ls] = ll[x];
        rr[ls] = mid;
        ll[rs] = mid + 1;
        rr[rs] = rr[x];
    }
    int valtot = (1 << nt);
    std::vector<std::vector<Range> > rg(valtot + 10);
    std::map<Range, int> map;
    for(int i = 1; i <= Q; ++i) {
        int p, x;scanf("%d%d", &p, &x);
        rg[x].emplace_back(ll[p], rr[p]);
        if(map.find({ll[p], rr[p]}) != map.end()) {
            if(map[{ll[p], rr[p]}] != x)
                return 0;
        }
        map[{ll[p], rr[p]}] = x;
    }
    std::vector<Range> mnrg(valtot + 10), mxrg(valtot + 10);
    std::map<Range, int> rgset;
    for(int x = 1; x <= valtot; ++x) {
        if(rg[x].size()) {
            std::sort(rg[x].begin(), rg[x].end());
            mnrg[x] = rg[x][0];
            mxrg[x] = rg[x].back();
            for(auto [l, r] : rg[x]) {
                if(!(l <= mnrg[x].l && mnrg[x].r <= r))
                    return 0;
            }
            // rgset.emplace(mnrg[x]);
            rgset[mnrg[x]] = x;
        }
    }

    i64 ans = 1;

    std::vector<int> cnt(tot + 10);
    std::vector<int> mxin(tot + 10);
    for (int x = tot; x >= 1; --x) {
        int ls = x * 2;
        int rs = x * 2 + 1;
        if(rs <= tot){
            cnt[x] = cnt[ls] + cnt[rs];
            mxin[x] = std::max(mxin[ls], mxin[rs]);
        }
        int len = rr[x] - ll[x] + 1;
        auto it = rgset.find(Range(ll[x], rr[x]));
        if(it != rgset.end()) {
            if(len - cnt[x] <= 0)
                return 0;
            ans = ans * (len - cnt[x]) % MOD;
            ++cnt[x];
            int curv = it->second;
            if(curv < mxin[x])
                return 0;
            mxin[x] = std::max(mxin[x], curv);
        }
    }

    std::set<std::pair<int, int> > tmp;
    i64 tmplen = 0;
    for(int x = 1; x <= valtot; ++x) {
        if(mxrg[x].l) {
            insert(mxrg[x].l, mxrg[x].r, tmp, tmplen);
        }
    }
    std::vector<int> vis(valtot + 10);
    for(auto [l, r] : tmp) {
        for(int i = l; i <= r; ++i)
            vis[i] = 1;
    }
    std::set<std::pair<int, int> > set;
    i64 totlen = 0;
    for(int x = 1; x <= valtot; ++x) {
        if(vis[x])
            continue;
        insert(x, x, set, totlen);
    }

    for(int x = valtot; x >= 1; --x) {
        if(mnrg[x].l || mnrg[x].r) {
            insert(mxrg[x].l, mxrg[x].r, set, totlen);
        } else {
            i64 bk = valtot - x;
            i64 rest = totlen - bk;
            if(rest <= 0)
                return 0;
            ans = ans * rest % MOD;
        }
    }
    return ans;
}

int main() {
    i64 ans = solve();
    printf("%lld", ans);

    return 0;
}