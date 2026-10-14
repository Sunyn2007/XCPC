#include <bits/stdc++.h>
using namespace std;
const int H = 2e5;
int h, w;
long long ans;
string s[H + 5];
vector<int> a[H + 5], u[H + 5], l[H + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        cin >> s[i], s[i] = ' ' + s[i];
        a[i].resize(w + 1), u[i].resize(w + 1), l[i].resize(w + 1);
    }
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            if (s[i][j] == '.') u[i][j] = i, l[i][j] = j;
            else {
                if (i == 1) u[i][j] = 0;
                else u[i][j] = u[i - 1][j];
                if (j == 1) l[i][j] = 0;
                else l[i][j] = l[i][j - 1];
            }
            ans += u[i][j] * l[i][j];
        }
    cout << ans;
    return 0;
}