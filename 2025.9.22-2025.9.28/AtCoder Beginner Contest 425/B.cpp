#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, a[N + 5], p[N + 5];
bool book[N + 5], flag = true;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != -1) {
            if (book[a[i]]) flag = false;
            book[a[i]] = true;
            p[i] = a[i];
        }
    }
    if (!flag) cout << "No";
    else {
        for (int i = 1; i <= n; i++)
            if (a[i] == -1) {
                for (int j = 1; j <= n; j++)
                    if (!book[j]) {
                        p[i] = j;
                        book[j] = true;
                        break;
                    }
            }
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) cout << p[i] << ' ';
    }
    return 0;
}