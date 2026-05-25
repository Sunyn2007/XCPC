#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, a[N + 5], ans;
map<int, bool> book;
void insert(int x) {
    if (book.find(x) == book.end()) {
        book[x] = true;
        ans += 1;
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    for (int i = 1; i < n; i++) {
        int x = a[i] ^ a[i + 1], y = a[i] | a[i + 1], z = a[i] & a[i + 1];
        insert(x), insert(y), insert(z);
        insert(a[i] ^ y), insert(a[i] ^ z);
        insert((a[i] ^ y) | z);
        insert((a[i] ^ z) | z);
    }
    insert(0);
    cout << ans;
    return 0;
}