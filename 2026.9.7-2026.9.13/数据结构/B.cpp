#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
int n;
void print(Node *head) {
    for (Node *p = head->next; p != nullptr; p = p->next)
        cout << p->data << ' ';
    cout << '\n';
}
void swapNode(Node *head, int pa, int pb) {
    if (pa < 1 || pb < 1 || pa > n || pb > n) {
        cout << "error\n";
        return;
    }
    if (pa == pb) {
        print(head);
        return;
    }
    if (pa > pb) swap(pa, pb);
    Node *prea = head, *preb = head;
    for (int i = 1; i < pa; ++i) prea = prea->next;
    for (int i = 1; i < pb; ++i) preb = preb->next;
    Node *a = prea->next, *b = preb->next;
    if (pa + 1 == pb) {
        prea->next = b;
        a->next = b->next;
        b->next = a;
    } else {
        Node *tmp = a->next;
        prea->next = b;
        preb->next = a;
        a->next = b->next;
        b->next = tmp;
    }
    print(head);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    Node *head = new Node{0, nullptr};
    Node *tail = head;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tail->next = new Node{x, nullptr};
        tail = tail->next;
    }
    print(head);
    for (int t = 0; t < 2; ++t) {
        int pa, pb;
        cin >> pa >> pb;
        swapNode(head, pa, pb);
    }
    return 0;
}
