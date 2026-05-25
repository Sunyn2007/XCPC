#include <bits/stdc++.h>
using namespace std;
const int N = 4e4;
int n, m, a[N + 5], lst[N + 5], dp[N + 5];
set<int> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    s.insert(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (lst[a[i]]) s.erase(lst[a[i]]);
        s.insert(i), lst[a[i]] = i;
        dp[i] = i;
        int k = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            dp[i] = min(dp[i], dp[*it] + k * k);
            k += 1;
            if (k * k > dp[i]) break;
        }
    }
    cout << dp[n];
    return 0;
}