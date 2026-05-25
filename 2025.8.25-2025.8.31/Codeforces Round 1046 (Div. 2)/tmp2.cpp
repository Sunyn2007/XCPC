#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
    long long a, b;
    cin >> a >> b;
    while (true) {
        char opt;
        long long k;
        cin >> opt >> k;
        if (opt == 'U') b += k;
        if (opt == 'D') b -= k;
        if (opt == 'R') a += k;
        if (opt == 'L') a -= k;
        cout << a << ' ' << b << "\n"; 
    }
    return 0;
}