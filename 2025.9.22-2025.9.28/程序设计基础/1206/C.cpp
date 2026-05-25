#include <bits/stdc++.h>
using namespace std;
int n;
double tot;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double tmp;
        cin >> tmp;
        tot += tmp;
    }
    cout << fixed << setprecision(2) << tot / n;
    return 0;
}