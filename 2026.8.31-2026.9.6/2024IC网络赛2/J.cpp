#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
struct syn {
    int w, c;
    long long v;
}a[N + 5];
int n;
long long sw, sv;
bool cmp(syn a, syn b) {
    return 1ll * a.c * b.w > 1ll * b.c * a.w;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].v >> a[i].c;
        sw += a[i].w, sv += a[i].v;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        sw -= a[i].w;
        sv -= a[i].c * sw;
    }
    cout << sv;
    return 0;
}