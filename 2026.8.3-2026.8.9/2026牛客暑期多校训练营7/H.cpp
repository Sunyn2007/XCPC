#include <bits/stdc++.h>
using namespace std;
int p[15];
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    for (int i = 15; i <= 15; i++) {
        for (int j = 0; j < i; j++) p[j + 1] = j;
        swap(p[1], p[8]);
        do {
            bool fl = true;
            for (int j = 1; j < i; j += 3)
                if (p[j + 1] == 0 || p[j] % p[j + 1] != p[j + 2]) fl = false;
            for (int j = 4; j < i; j += 3)
                if (p[j] < p[j - 3]) fl = false;
            if (fl) {
                for (int j = 1; j <= i; j++) cout << p[j] << ' ';
                cout << '\n';
            }
        } while(next_permutation(p + 1, p + i + 1));
    }
    return 0;
}