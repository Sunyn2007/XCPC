#include <bits/stdc++.h>
using namespace std;
int a[1005], b[1005], c[2005], n, m, len;
void print() {
    cout << len << ' ';
    for (int i = 1; i <= len; ++i) cout << c[i] << ' ';
    cout << "\n";
    return ;
}
void merge() {
    int i = 1, j = 1;
    len = 0;
    while (i <= n && j <= m) {
        if (a[i] < b[j]) c[++len] = a[i++];
        else c[++len] = b[j++];
    }
    while (i <= n) c[++len] = a[i++];
    while (j <= m) c[++len] = b[j++];
    print();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; ++i) cin >> b[i];
        merge();
    }
    return 0;
}