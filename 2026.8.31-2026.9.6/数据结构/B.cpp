#include <bits/stdc++.h>
using namespace std;
int a[1005], n;
void print() {
    cout << n << ' ';
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << "\n";
    return ;
}
void mulins(int pos, int k, int item[]) {
    for (int i = n; i >= pos; --i) a[i + k] = a[i];
    for (int i = 0; i < k; ++i) a[pos + i] = item[i];
    n += k;
    print();
    return ;
}
void muldel(int pos, int k) {
    for (int i = pos + k; i <= n; ++i) a[i - k] = a[i];
    n -= k;
    print();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    print();
    int pos, k;
    cin >> pos >> k;
    int item[1005];
    for (int i = 0; i < k; ++i) cin >> item[i];
    mulins(pos, k, item);
    cin >> pos >> k;
    muldel(pos, k);
    return 0;
}