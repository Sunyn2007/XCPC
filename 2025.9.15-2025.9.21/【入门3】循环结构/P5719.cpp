#include <bits/stdc++.h>
using namespace std;
int n, k, cnt1, cnt2;
double sum1, sum2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) sum1 += i, cnt1 += 1;
        else sum2 += i, cnt2 += 1;
    }
    cout << fixed << setprecision(1) << sum1 / cnt1 << ' ';
    cout << fixed << setprecision(1) << sum2 / cnt2;
    return 0;
}