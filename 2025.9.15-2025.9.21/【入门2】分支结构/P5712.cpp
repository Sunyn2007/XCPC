#include <bits/stdc++.h>
using namespace std;
int x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> x;
    if (x <= 1) cout << "Today, I ate " << x << " apple.";
    else cout << "Today, I ate " << x << " apples.";
    return 0;
}