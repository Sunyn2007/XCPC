#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;
int t, x, y;
ll dp[35][3][3];
pair<int, int> rec[35][3][3];
ll dfs(int bit, int cx, int cy) {
    if (bit < 0) return 0;
    if (dp[bit][cx][cy] != -1) return dp[bit][cx][cy];
    ll res = INF;
    pair<int, int> best = {-1, -1};
    int xb = (x >> bit) & 1;
    int yb = (y >> bit) & 1;
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            if (p & q) continue;
            int ncx = cx, ncy = cy;
            if (cx == 0) {
                if (p < xb) ncx = 1;
                else if (p > xb) ncx = 2;
            }
            if (cy == 0) {
                if (q < yb) ncy = 1;
                else if (q > yb) ncy = 2;
            }
            ll val = dfs(bit - 1, ncx, ncy);
            ll w = 1LL << bit;
            if (ncx == 1) val += (xb - p) * w;
            else if (ncx == 2) val += (p - xb) * w;
            if (ncy == 1) val += (yb - q) * w;
            else if (ncy == 2) val += (q - yb) * w;
            if (val < res) {
                res = val;
                best = {p, q};
            }
        }
    }
    rec[bit][cx][cy] = best;
    return dp[bit][cx][cy] = res;
}
void solve() {
    cin >> x >> y;
    for (int i = 0; i <= 30; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) dp[i][j][k] = -1;        
    dfs(30, 0, 0);
    int ap = 0, aq = 0, cx = 0, cy = 0;
    for (int i = 30; i >= 0; i--) {
        pair<int, int> mov = rec[i][cx][cy];
        int p = mov.first;
        int q = mov.second;
        if (p) ap |= (1 << i);
        if (q) aq |= (1 << i);
        int xb = (x >> i) & 1;
        int yb = (y >> i) & 1;
        if (cx == 0) {
            if (p < xb) cx = 1;
            else if (p > xb) cx = 2;
        }
        if (cy == 0) {
            if (q < yb) cy = 1;
            else if (q > yb) cy = 2;
        }
    }
    cout << ap << " " << aq << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}