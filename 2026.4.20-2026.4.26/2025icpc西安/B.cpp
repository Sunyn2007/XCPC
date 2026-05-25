#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
int t, n, sl, sr, ansl, ansr;
char s[N + 5];
int h(char ch) {
    if (ch == 'C') return 0;
    else if (ch == 'W') return 1;
    else if (ch == 'P') return 2;
    else return 3;
}
char syn(int x) {
    if (x == 0) return 'C';
    if (x == 1) return 'W';
    if (x == 2) return 'P';
}
bool check(int len) {
    int cnt[3] = {0, 0, 0};
    for (int i = 1; i <= len; i++) cnt[h(s[i])] += 1;
    for (int i = 1; i + len - 1 <= n; i++) {
        if (i + len - 1 > len) cnt[h(s[i + len - 1])] += 1;
        if (i <= sl && i + len - 1 >= sr) {
            bool flag = true;
            for (int j = 0; j <= 2; j++) {
                int tmp = 0;
                if (h(s[i - 1]) == j) tmp += 1;
                if (h(s[i + len]) == j) tmp += 1;
                if (!tmp && cnt[j] > (len + 1) / 2) flag = false;
                if (tmp == 1 && cnt[j] > len / 2) flag = false;
                if (tmp == 2 && cnt[j] > (len - 1) / 2) flag = false;
            }
            if (flag) {
                ansl = i, ansr = i + len - 1;
                return true;
            } 
        }
        cnt[h(s[i])] -= 1;
    }
    return false;
}
void solve() {
    cin >> n >> (s + 1);
    sl = sr = 0;
    for (int i = 2; i <= n; i++)
        if (s[i] == s[i - 1]) {
            sl = i;
            break;
        }
    for (int i = n - 1; i >= 1; i--)
        if (s[i] == s[i + 1]) {
            sr = i;
            break;
        }
    if (!sl) cout << "Beautiful" << '\n';
    else {
        int l = 2, r = n, mid, ans = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (ans) {
            cout << "Possible" << '\n' << ansl << ' ' << ansr << '\n';
            int cnt[3] = {0, 0, 0};
            for (int i = ansl; i <= ansr; i++) cnt[h(s[i])] += 1;
            for (int i = ansl; i <= ansr; i++) {
                int tmp;
                if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2] && h(s[ansr + 1]) == 0) tmp = 0;
                else if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2] && h(s[ansr + 1]) == 1) tmp = 1;
                else if (cnt[2] >= cnt[0] && cnt[2] >= cnt[1] && h(s[ansr + 1]) == 2) tmp = 2;
                else if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2]) tmp = 0;
                else if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2]) tmp = 1;
                else if (cnt[2] >= cnt[0] && cnt[2] >= cnt[1]) tmp = 2;
                if (h(s[i - 1]) == tmp) {
                    if (ansr < n && h(s[ansr + 1]) != h(s[i - 1]) && cnt[h(s[ansr + 1])]) s[i] = s[ansr + 1], cnt[h(s[ansr + 1])] -= 1;
                    else {
                        for (int j = 0; j <= 2; j++)
                            if (j != h(s[i - 1]) && cnt[j]) {
                                s[i] = syn(j), cnt[j] -= 1;
                                break;
                            }
                    }
                }
                else s[i] = syn(tmp), cnt[tmp] -= 1;
            } 
            cout << (s + 1) << '\n';
        }
        else cout << "Impossible" << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
4
5
CWCWC
6
CWCCPW
3
PPP
8
CWPPCWWC
*/