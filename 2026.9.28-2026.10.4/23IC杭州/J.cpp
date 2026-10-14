#include <cstdio>
#include <cstring>
#include <vector>

int query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int first(int n, std::vector<int>& vis) {
    for (int i = 1; i <= n; ++i)
        if(!vis[i]) {
            vis[i] = 1;
            return i;
        }
    return n + 1;
}

void solve() {
    int n;scanf("%d", &n);
    bool mustchain = true;
    int x = 0, y = 0;
    for (int i = 1; i + 1 <= n; i += 2) {
        if(query(i, i + 1)) {
            mustchain = false;
            x = i;
            y = i + 1;
        }
    }
    if(n & 1) {
        if(query(1, n)) {
            mustchain = false;
            x = 1;
            y = n;
        }
    }
    std::vector<int> vis(n + 2);
    vis[x] = vis[y] = 1;
    if(mustchain) {
        printf("! 1\n");
        fflush(stdout);
        return;
    }
    int z = 0;
    int fir = first(n, vis);
    int sec = first(n, vis);
    if(query(x, fir)) {
        z = x;
    }
    if(query(y, fir)) {
        z = y;
    }
    if(z == 0) {
        printf("! 1\n");
        fflush(stdout);
        return;
    }
    if(query(z, sec)) {
        printf("! 2\n");
        fflush(stdout);
        return;
    } else {
        printf("! 1\n");
        fflush(stdout);
        return;
    }
}

int main() {
    int T;scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}