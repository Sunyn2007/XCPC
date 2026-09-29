#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::vector<std::set<int> > Graph;

void addEdge(Graph &g, int x, int y) {
    g[x].emplace(y);
    g[y].emplace(x);
}

bool vis[500010];
int p[500010];
int novis[500010];
int cur = 1;

std::vector<std::pair<int, int> > ans;

void dfs(int x, Graph &g) {
    vis[x] = 1;
    for(auto y : g[x])
        --novis[y];
    while(p[cur]) {
        if(g[x].find(p[cur]) != g[x].end()) {
            ++cur;
            dfs(p[cur - 1], g);
        } else {
            // bool allvis = true;
            // for (auto y : g[x]) {
            //     if(!vis[y])
            //         allvis = false;
            // }
            if(novis[x] == 0) {
                return;
            } else {
                int y = p[cur];
                g[x].emplace(y);
                g[y].emplace(x);
                ++novis[x];

                ans.emplace_back(x, p[cur]);
                ++cur;
                dfs(p[cur - 1], g);
            }
        }
    }
}

int main() {
    int n, m;scanf("%d%d", &n, &m);
    Graph g(n + 2);
    for (int i = 1; i <= m; ++i) {
        int x, y;scanf("%d%d", &x, &y);
        addEdge(g, x, y);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", p + i);
    
    for (int x = 1; x <= n; ++x) {
        novis[x] = (int)g[x].size();
    } 

    while(p[cur]) {
        ++cur;
        dfs(p[cur - 1], g);
    }
    printf("%d\n", (int)ans.size());
    for (auto [x, y] : ans)
        printf("%d %d\n", x, y);


    return 0;
}