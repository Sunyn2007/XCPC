#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
long long s1[N + 5], s2[N + 5];
vector<int> ans;
int syn(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], s1[i] = s1[i - 1] + a[i], s2[i] = s2[i - 1] + syn(a[i]);
    long long maxs = s1[n];
    int p = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > 0) {
            long long s = -a[i] + s1[n] - s1[i] + s2[i - 1];
            if (s > maxs) maxs = s, p = i;
        }
    bool tag = false;
    for (int i = p - 1; i >= 1; i--) {
        if (a[i] > 0 && !tag) ans.push_back(i), tag = !tag;
        if (a[i] < 0 && tag) ans.push_back(i), tag = !tag;
    }
    if (p) ans.push_back(p);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
    ans.clear(); 
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}