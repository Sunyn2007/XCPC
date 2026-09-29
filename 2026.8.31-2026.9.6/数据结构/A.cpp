#include <bits/stdc++.h>
using namespace std;
int a[1005], n;
void print() {
    cout << n << ' ';
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << "\n";
    return ;
}
void ins() {
    int pos, val;
    cin >> pos >> val;
    if (pos < 1 || pos > n + 1 || n >= 1000) cout << "error\n";
    else {
        for (int i = n; i >= pos; --i) a[i + 1] = a[i];
        a[pos] = val;
        n++;
        print();
    }
    return ;
}
void del() {
    int pos;
    cin >> pos;
    if (pos < 1 || pos > n) cout << "error\n";
    else {
        for (int i = pos; i < n; ++i) a[i] = a[i + 1];
        n--;
        print();
    }
    return ;
}
void find() {
    int pos;
    cin >> pos;
    if (pos < 1 || pos > n) cout << "error\n";
    else cout << a[pos] << "\n";
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        print();
        ins(), ins();
        del(), del();
        find(), find();
    }
    return 0;
}