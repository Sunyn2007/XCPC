#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n;
long long px[N + 5], py[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> px[i] >> py[i];
    for (int i = 2; i <= n - 1; i++) {
        if ((py[i] - py[i - 1]) * (px[i + 1] - px[i - 1]) == (py[i + 1] - py[i - 1]) * (px[i] - px[i - 1]))
            cout << "STRAIGHT" << ' ';
        else if ((px[i] - px[i - 1]) * (py[i + 1] - py[i - 1]) - (px[i + 1] - px[i - 1]) * (py[i] - py[i - 1]) > 0)
            cout << "LEFT" << ' ';
        else cout << "RIGHT" << ' ';
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}