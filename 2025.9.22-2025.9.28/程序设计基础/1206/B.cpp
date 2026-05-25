#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        double score;
        int num;
        char s;
        cin >> score >> num >> s;
        cout << num << '\n' << s << '\n' << score << '\n';
    }
    return 0;
}