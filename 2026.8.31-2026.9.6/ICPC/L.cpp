#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n, m, tr[N + 5][26], tot, dep[N + 5], cnt[N + 5], maxd[N + 5];
long long ans;
string s;
void ins(string s, int x) {
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (!tr[now][ch]) tr[now][ch] = ++tot;
        now = tr[now][ch];
        cnt[now] += 1, dep[now] = i + 1;
        if (dep[now] > maxd[cnt[now]]) {
            if (cnt[now] < x || maxd[cnt[now]]) ans -= maxd[cnt[now]] ^ cnt[now];
            maxd[cnt[now]] = dep[now];
            ans += maxd[cnt[now]] ^ cnt[now];
        }
    }
    if (!maxd[x]) ans += x;
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        ins(s, i);
        cout << ans << '\n';
    }
    return 0;
}