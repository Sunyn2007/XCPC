#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int t, n, len;
vector<int> res;
bool vis[N + 5];
int tot[N + 5];
void mkq(int x) {
    res.clear();
    cout << '?' << ' ' << x << '\n', cout.flush();
    cin >> len;
    for (int i = 1; i <= len; i++) {
        int tmp;
        cin >> tmp;
        res.push_back(tmp);
    }
    return ;
}
void solve() {
    cin >> n;
    int k = 1;
    vector<int> a;
    set<pair<int, int> > ans;
    k = 2, a.push_back(1), tot[1] = 1;
    while (true) {
        mkq(k);
        if (len == 0) break;
        while (a.size() >= len)
            vis[a.back()] = true, a.pop_back();
        if (!a.empty()) ans.insert(make_pair(a.back(), res.back()));
        a.push_back(res.back());
        if (vis[res.back()]) {
            for (int i = 0; i < a.size() - 1; i++) 
                tot[a[i]] += tot[res.back()];
            k += tot[res.back()];
        }
        else {
            for (int i = 0; i < a.size(); i++)
                tot[a[i]] += 1;
            k += 1;
        }
    }
    cout << '!' << ' ' << ans.size() << '\n';
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << (*it).first << ' ' << (*it).second << '\n';
    cout.flush();
    for (int i = 1; i <= n; i++)
        vis[i] = false, tot[i] = 0;
    return ;
}
int main() {
    cin >> t;
    while (t--) solve(); 
    return 0;
}