#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int t;
long long n, x;
void solve() {
    cin >> n >> x;
    long long cnt1, cnt2, ans;
    if (x % 2 == 1) {
        if (x / 2 % 2 == 1) {
            cnt1 = (n - x) / 4 + 1;
            if (x + 2 <= n) cnt2 = (n - x - 2) / 4 + 1; 
            else cnt2 = 0;
        }
        else {
            cnt2 = (n - x) / 4 + 1;
            if (x + 2 <= n) cnt1 = (n - x - 2) / 4 + 1; 
            else cnt1 = 0;
        }
    }
    else {
        if (x == n) cnt1 = cnt2 = 0;
        else if (x + 3 <= n) {
            if ((x + 1) / 2 % 2 == 1) {
                cnt1 = (n - x - 1) / 4 + 1;
                cnt2 = (n - x - 3) / 4 + 1;
            }
            else {
                cnt2 = (n - x - 1) / 4 + 1;
                cnt1 = (n - x - 3) / 4 + 1;
            }
        }
        else {
            if ((x + 1) / 2 % 2 == 1) {
                cnt1 = (n - x - 1) / 4 + 1;
                cnt2 = 0;
            }
            else {
                cnt2 = (n - x - 1) / 4 + 1;
                cnt1 = 0;
            }
        }
    }
    cout << (cnt1 % MOD * ((x / 4 + 1) % MOD) % MOD + cnt2 % MOD * ((x + 2) / 4 % MOD) % MOD) % MOD << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}