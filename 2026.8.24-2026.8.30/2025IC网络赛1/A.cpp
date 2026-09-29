#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, num, prb[N + 5], pnt[N + 5], tmp[N + 5][26], dprb[N + 5], dpnt[N + 5];
map<string, int> bk;
struct syn {
    int tsk, tm;
    string sta;
};
bool ac[N + 5][26];
vector<syn> a[N + 5];
bool cmp(syn a, syn b) {
    return a.tm < b.tm;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string name, sta;
        char tsk;
        int tm, id;
        cin >> name >> tsk >> tm >> sta;
        if (!bk[name]) bk[name] = ++num;
        id = bk[name];
        a[id].push_back({tsk - 'A', tm, sta});
    }
    int sprb = 0, spnt = 0;
    for (int i = 1; i <= num; i++) {
        sort(a[i].begin(), a[i].end(), cmp);
        for (auto x : a[i]) {
            if (ac[i][x.tsk]) continue;
            if (x.tm < 240) {
                if (x.sta == "Rejected") tmp[i][x.tsk] += 20;
                else ac[i][x.tsk] = true, prb[i] += 1, pnt[i] += x.tm + tmp[i][x.tsk];
            }
            else ac[i][x.tsk] = true, dprb[i] += 1, dpnt[i] += x.tm + tmp[i][x.tsk];
        }
        if (prb[i] > sprb) sprb = prb[i], spnt = pnt[i];
        else if (prb[i] == sprb && pnt[i] < spnt) spnt = pnt[i];
    }
    for (auto [x, y] : bk) {
        if (prb[y] + dprb[y] > sprb || (prb[y] + dprb[y] == sprb && pnt[y] + dpnt[y] <= spnt))
            cout << x << ' ';
    }
    cout << '\n';
    bk.clear();
    for (int i = 1; i <= num; i++) {
        prb[i] = pnt[i] = dprb[i] = dpnt[i] = 0;
        a[i].clear();
        for (int j = 0; j < 26; j++)
            ac[i][j] = false, tmp[i][j] = 0;
    }
    num = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}