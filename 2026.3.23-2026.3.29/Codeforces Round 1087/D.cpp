#include <bits/stdc++.h>
using namespace std;
int t, r, g, b;
string ans;
void dfs(int r, int g, int b, int x) {
    if (!x) {
        if (r && g && b) {
            if (r == g && g == b)
                ans += "rgb", dfs(r - 1, g - 1, b - 1, 2);
            else if (r >= g && r >= b) {
                if (g >= b) ans += "rgr", dfs(r - 2, g - 1, b, )
            }
        }
        else {
            
        }
    }
    else {

    }
}
void solve() {
    cin >> r >> g >> b;
    dfs(r, g, b, 0);
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}