#include <bits/stdc++.h>
using namespace std;
int pri(char c) {          
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    cout << fixed << setprecision(4);
    while (t--) {
        string str;
        char c;
        while (cin.get(c)) {       
            if (c == '#') break;
            if (!isspace((unsigned char)c)) str += c;
        }
        stack<double> num;
        stack<char> op;
        auto apply = [&]() {       
            double b = num.top(), a;
            num.pop();
            a = num.top();
            num.pop();
            char o = op.top();
            op.pop();
            if (o == '+') a += b;
            else if (o == '-') a -= b;
            else if (o == '*') a *= b;
            else a /= b;
            num.push(a);
        };
        int i = 0, n = (int)str.size();
        while (i < n) {
            char ch = str[i];
            if (isdigit((unsigned char)ch) || ch == '.') {
                double v = 0;
                while (i < n && isdigit((unsigned char)str[i])) v = v * 10 + (str[i++] - '0');
                if (i < n && str[i] == '.') {          
                    ++i;
                    double w = 0.1;
                    while (i < n && isdigit((unsigned char)str[i])) {
                        v += (str[i++] - '0') * w;
                        w *= 0.1;
                    }
                }
                num.push(v);
            } else if (ch == '(') {
                op.push(ch);
                ++i;
            } else if (ch == ')') {
                while (op.top() != '(') apply();
                op.pop();                              
                ++i;
            } else {                                   
                while (!op.empty() && op.top() != '(' && pri(op.top()) >= pri(ch)) apply();
                op.push(ch);
                ++i;
            }
        }
        while (!op.empty()) apply();
        cout << num.top() << '\n';
    }
    return 0;
}
