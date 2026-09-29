#include <bits/stdc++.h>
using namespace std;
int t, n, p;
void solve() {
    cin >> n >> p;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'U') {
            if (s == "UnreasonableProblemArrangement") sum += 10;
            if (s.size() == 28 && s.substr(0, 27) == "UnreasonableLimitForProblem" && s.back() >= 'A' && s.back() <= 'L') sum += 5;
        }
        if (s[0] == 'W') {
            if (s.size() == 13 && s.substr(0, 12) == "WrongProblem" && s.back() >= 'A' && s.back() <= 'L') sum += 100;
            if (s.size() == 20 && s.substr(0, 19) == "WeakTestsForProblem" && s.back() >= 'A' && s.back() <= 'L') sum += 3;
        }
        if (s[0] == 'S') {
            if (s.size() == 12 && s.substr(0, 11) == "SameProblem" && s.back() >= 'A' && s.back() <= 'L') sum += 30;
        }
        if (s[0] == 'B') {
            if (s.size() == 11 && s.substr(0, 10) == "BadProblem" && s.back() >= 'A' && s.back() <= 'L') sum += 1;
        }
    }
    if (sum > p) cout << "Joker" << '\n';
    else cout << "Judger" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
}