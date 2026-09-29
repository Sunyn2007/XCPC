#include <bits/stdc++.h>
using namespace std;
struct Node {
    int coef;
    int exp;
    Node *next;
};
void out(int x) {
    if (x < 0) cout << '(' << x << ')';
    else cout << x;
}
void print(Node *head) {
    bool first = true;
    for (Node *p = head->next; p != nullptr; p = p->next) {
        if (p->coef == 0) continue;
        if (!first) cout << " + ";
        first = false;
        out(p->coef);
        if (p->exp != 0) {
            cout << "x^";
            out(p->exp);
        }
    }
    cout << '\n';
}
void insert(Node *head, int coef, int exp) {
    Node *pre = head;
    while (pre->next != nullptr && pre->next->exp < exp) pre = pre->next;
    if (pre->next != nullptr && pre->next->exp == exp) {
        pre->next->coef += coef;
        return;
    }
    pre->next = new Node{coef, exp, pre->next};
}
Node *readPoly(int n) {
    Node *head = new Node{0, 0, nullptr};
    Node *tail = head;
    for (int i = 0; i < n; ++i) {
        int coef, exp;
        cin >> coef >> exp;
        tail->next = new Node{coef, exp, nullptr};
        tail = tail->next;
    }
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        Node *La = readPoly(n);
        cin >> m;
        Node *Lb = readPoly(m);
        print(La);
        print(Lb);
        Node *Lc = new Node{0, 0, nullptr};
        for (Node *p = La->next; p != nullptr; p = p->next) insert(Lc, p->coef, p->exp);
        for (Node *p = Lb->next; p != nullptr; p = p->next) insert(Lc, p->coef, p->exp);
        print(Lc);
    }
    return 0;
}
