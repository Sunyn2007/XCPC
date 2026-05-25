#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, v = 255, sa[N + 5], rk[N + 5], cnt[N + 5];
char s[N + 5];
struct syn {
    int id, x, y;
}t1[N + 5], t2[N + 5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s + 1, n = strlen(s + 1);
    for (int i = 1; i <= n; i++) rk[i] = s[i];
    for (int len = 1; len <= n; len <<= 1) {
        for (int i = 1; i <= n; i++)
            t1[i] = {i, rk[i], (i + len <= n) ? rk[i + len] : 0};
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t1[i].y] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t2[cnt[t1[i].y]--] = t1[i];
        for (int i = 0; i <= v; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[t2[i].x] += 1;
        for (int i = 1; i <= v; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) t1[cnt[t2[i].x]--] = t2[i];
        int num = 0;
        for (int i = 1; i <= n; i++) {
            if (i == 1 || t1[i].x != t1[i - 1].x || t1[i].y != t1[i - 1].y) num += 1;
            rk[t1[i].id] = num;
        }
        if (num == n) break;
        else v = num;
    }
    for (int i = 1; i <= n; i++) sa[rk[i]] = i;
    for (int i = 1; i <= n; i++) cout << sa[i] << ' ';
    return 0;
}