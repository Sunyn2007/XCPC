#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
#include <set>
#include <stack>
#include <map>

struct Opr {
    int tp;//1 -- insert, 2 -- T, 3 -- F
    int val;
};

char str[10];

void solve() {
    int n;scanf("%d", &n);
    std::vector<Opr> ops(n + 2);
    for (int i = 1; i <= n; ++i) {
        int x;scanf("%s%d", str, &x);
        if(str[0] == '+') {
            ops[i].tp = 1;
            ops[i].val = x;
        } else if(str[0] == 'T') {
            ops[i].tp = 2;
            ops[i].val = x;
        } else if(str[0] == 'F') {
            ops[i].tp = 3;
            ops[i].val = x;
        }
    }
    std::map<int, int> map;
    std::vector<int> nxt(n + 2);
    for (int i = n; i >= 1; --i) {
        nxt[i] = map[ops[i].val];
        map[ops[i].val] = ops[i].tp;
    }
    std::map<int, bool> set;
    std::stack<int> stack;
    std::vector<char> ans;
    for (int i = 1; i <= n; ++i) {
        int tp = ops[i].tp;
        int val = ops[i].val;
        if(tp == 1) {
            bool can = 0;
            if(nxt[i] != 2)
                can = 1;
            stack.emplace(val);
            set.emplace(val, can);
            ans.emplace_back('+');
        } else if(tp == 2) {
            bool can = 0;
            if(nxt[i] != 2)
                can = 1;
            set[val] = can;
            ans.emplace_back('?');
        } else if(tp == 3) {
            ans.emplace_back('?');
        }
        while(stack.size()) {
            if(!set[stack.top()])
                break;
            set.erase(stack.top());
            stack.pop();
            ans.emplace_back('-');
        }
    }

    for(auto c : ans)
        putchar(c);
    printf("\n");
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }


    return 0;
}