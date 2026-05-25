#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[2 * N + 5], book[N + 5];
vector<int> ans;
void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    int sta = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (book[a[i]] != sta) book[a[i]] = sta;
        else ans.push_back(i - 1), sta = 3 - sta;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
    ans.clear();
    for (int i = 1; i <= n; i++) book[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
4
1 1 2 2 3 3 4 4 
*/