#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
int n, m;
void print(Node *head) {
    for (Node *p = head->next; p != nullptr; p = p->next)
        cout << p->data << ' ';
    cout << '\n';
}
int LL_merge(Node *La, Node *Lb) {
    Node *pa = La->next, *pb = Lb->next, *pc = La;
    while (pa != nullptr && pb != nullptr) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa != nullptr ? pa : pb;
    delete Lb;
    return n + m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    Node *La = new Node{0, nullptr};
    Node *tail = La;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tail->next = new Node{x, nullptr};
        tail = tail->next;
    }
    cin >> m;
    Node *Lb = new Node{0, nullptr};
    tail = Lb;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        tail->next = new Node{x, nullptr};
        tail = tail->next;
    }
    LL_merge(La, Lb);
    print(La);
    return 0;
}
