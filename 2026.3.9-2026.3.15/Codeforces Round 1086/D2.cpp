#include <bits/stdc++.h>
using namespace std;
const int N = 8005;
int t, n;
string s[N];
int p[N];
int eu[N], ev[N], ecnt;
int adj[N][N], deg[N];
char check_s[N][N];
int q[N], ql, qr;
int c[N], ord[N];
bool vis[N];
int find_set(int x) { return p[x] == x ? x : p[x] = find_set(p[x]); }
bool cmp(int a, int b) { return c[a] > c[b]; }
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        c[i] = 0;
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') c[i]++;
        }
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    ecnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) vis[j] = false;
        for (int k = 0; k < n; k++) {
            int v = ord[k];
            if (i != v && s[i][v] == '1' && !vis[v]) {
                if (ecnt < n) {
                    eu[ecnt] = i;
                    ev[ecnt] = v;
                    ecnt++;
                }
                for (int w = 0; w < n; w++) {
                    if (s[v][w] == '1') vis[w] = true;
                }
            }
        }
    }
    if (ecnt != n - 1) {
        cout << "No\n";
        return;
    }
    iota(p, p + n, 0);
    for (int i = 0; i < n; i++) deg[i] = 0;
    for (int i = 0; i < ecnt; i++) {
        int u = find_set(eu[i]), v = find_set(ev[i]);
        if (u == v) {
            cout << "No\n";
            return;
        }
        p[u] = v;
        adj[eu[i]][deg[eu[i]]++] = ev[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) check_s[i][j] = '0';
        check_s[i][n] = '\0';
        ql = qr = 0;
        q[qr++] = i;
        check_s[i][i] = '1';
        while (ql < qr) {
            int u = q[ql++];
            for (int j = 0; j < deg[u]; j++) {
                int v = adj[u][j];
                if (check_s[i][v] == '0') {
                    check_s[i][v] = '1';
                    q[qr++] = v;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (s[i][j] != check_s[i][j]) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < ecnt; i++) cout << eu[i] + 1 << " " << ev[i] + 1 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}