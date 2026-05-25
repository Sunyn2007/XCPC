#include <bits/stdc++.h>
using namespace std;
long long syn(long long x) {
    return x < 0 ? -x : x;
}
long long dis(long long x1, long long y1, long long x2, long long y2) {
    return syn(x1 - x2) + syn(y1 - y2);
}
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << dis(a, b, c, d);
    return 0;
}