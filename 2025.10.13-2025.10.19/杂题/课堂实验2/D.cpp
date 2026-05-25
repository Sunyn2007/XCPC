#include <bits/stdc++.h>
using namespace std;
int r, g, b;
int main() {
    cin >> hex >> r >> g >> b;
    r = 255 - r, g = 255 - g, b = 255 - b;
    cout << hex << setiosflags(ios::uppercase) << setw(2) << setfill('0') << r << setw(2) << setfill('0') << g << setw(2) << setfill('0') << b;
    return 0;
}