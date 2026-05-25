#include <bits/stdc++.h>
using namespace std;
int n, a[55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (true) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1) cnt += 1;
        if (cnt > n / 2) {
            cout << "Bob";
            break;
        }
        else if (cnt) {
            cout << "Alice";
            break;
        }
        else {
            for (int i = 1; i <= n; i++) 
                a[i] -= 1;
        }
    }
    return 0;
}