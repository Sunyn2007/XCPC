#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, a[N + 5];
priority_queue<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    long long sum1 = 0, sum2 = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 0) {
            sum1 += a[i];
            ans += 1;
        }
        else {
            sum2 += a[i];
            ans += 1;
            q.push(-a[i]);
            if (sum1 + sum2 < 0) {
                sum2 -= -q.top(), q.pop();
                ans -= 1;
            }
        }
    }
    cout << ans;
    return 0;
}