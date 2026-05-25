#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5], book[N + 5];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (a[1] != 0) cout << (k % 2 == 0 ? n : 0) << '\n';
    else {
        int minn = -1, maxn = 0;
        for (int i = 2; i <= n; i++) {
            if (minn == -1 && a[i] == a[i - 1]) minn = a[i];
            if (a[i] == a[i - 1] || a[i] == a[i - 1] + 1) maxn = a[i];
            else break;  
        }
        if (minn == -1) {
            if (maxn + 1 == n - 1) cout << (long long)(0 + maxn + 1) * n / 2 << '\n';
            else {
                long long sum = (long long)(0 + maxn) * (maxn + 1) / 2;
                if (k % 2 == 1) cout << sum + (long long)(maxn + 1) * (n - (maxn + 1)) << '\n';
                else cout << sum + (long long)(maxn + 2) * (n - (maxn + 1)) << '\n';
            }
        }
        else {
            long long sum = 0;
            int cnt = 0, lst = 0;
            while (a[lst + 1] <= maxn && lst + 1 <= n) lst += 1, book[a[lst]] += 1;
            for (int i = 1; i <= lst; i++) {
                if (book[a[i]] >= 2) cnt += 1;
                else sum += a[i];
            }
            if (k == 1) cout << sum + (long long)(maxn + 1) * (n - lst + cnt) << '\n';
            else {
                sum = (long long)(0 + minn - 1) * minn / 2;
                if (k % 2 == 0) cout << sum + (long long)minn * (n - minn) << '\n';
                else cout << sum + (long long)(minn + 1) * (n - minn) << '\n';
            }
            for (int i = 0; i <= maxn; i++) book[i] = 0;
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
1
2 4 
0 2
*/