#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sz(n + 1);
    auto dfs_sz = [&](auto& self, int u, int p) -> void {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };

    dfs_sz(dfs_sz, 1, 0);

    auto get_centroid = [&](auto& self, int u, int p, int total) -> int {
        for (int v : adj[u]) {
            if (v == p) continue;
            if (sz[v] > total / 2) return self(self, v, u, total);
        }
        return u;
    };

    int R = get_centroid(get_centroid, 1, 0, n);
    dfs_sz(dfs_sz, R, 0);

    vector<long long> ans(n + 1, 0);

    auto dfs_S = [&](auto& self, int u, int p, int mx, vector<int>& S) -> void {
        S.push_back(max(sz[u], mx));
        for (int v : adj[u]) {
            if (v == p) continue;
            self(self, v, u, max(mx, sz[u] - sz[v]), S);
        }
    };

    for (int w = 1; w <= n; w++) {
        ans[n]++;
        map<int, long long> count_sz;
        for (int v : adj[w]) {
            if (sz[v] > sz[w]) continue; 
            ans[n - sz[v]] += sz[v];
            count_sz[sz[v]]++;
        }

        if (w != R) {
            for (auto it1 = count_sz.begin(); it1 != count_sz.end(); ++it1) {
                long long s1 = it1->first, c1 = it1->second;
                ans[n - 2 * s1] += s1 * s1 * c1 * (c1 - 1) / 2;
                for (auto it2 = next(it1); it2 != count_sz.end(); ++it2) {
                    long long s2 = it2->first, c2 = it2->second;
                    ans[n - s1 - s2] += (s1 * c1) * (s2 * c2);
                }
            }
        } else {
            int L = -1;
            int max_sz = -1;
            for (int v : adj[w]) {
                if (sz[v] > max_sz) {
                    max_sz = sz[v];
                    L = v;
                }
            }
            if (L != -1) {
                map<int, long long> count_not_L;
                for (int v : adj[R]) {
                    if (v != L) count_not_L[sz[v]]++;
                }
                for (auto it1 = count_not_L.begin(); it1 != count_not_L.end(); ++it1) {
                    long long s1 = it1->first, c1 = it1->second;
                    ans[n - 2 * s1] += s1 * s1 * c1 * (c1 - 1) / 2;
                    for (auto it2 = next(it1); it2 != count_not_L.end(); ++it2) {
                        long long s2 = it2->first, c2 = it2->second;
                        ans[n - s1 - s2] += (s1 * c1) * (s2 * c2);
                    }
                }

                vector<int> SL;
                dfs_S(dfs_S, L, R, 0, SL);
                sort(SL.begin(), SL.end());
                vector<long long> suffix_adds(SL.size() + 1, 0);

                for (int y : adj[R]) {
                    if (y == L) continue;
                    vector<int> SY;
                    dfs_S(dfs_S, y, R, 0, SY);
                    for (int b : SY) {
                        int M = max((int)(n - sz[L] - sz[y]), b);
                        int idx = upper_bound(SL.begin(), SL.end(), M) - SL.begin();
                        ans[M] += idx;
                        suffix_adds[idx]++;
                    }
                }

                long long running = 0;
                for (size_t i = 0; i < SL.size(); i++) {
                    running += suffix_adds[i];
                    ans[SL[i]] += running;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}