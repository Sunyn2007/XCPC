#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size(), ans = -1;
        for (int d = 1; d < n; ++d) {
            int c = 0;
            for (int i = n - d - 1; i >= 0; --i) {
                c = (s[i] == s[i + d]) ? c + 1 : 0;
                if (c) ans = max(ans, min(c, d));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
