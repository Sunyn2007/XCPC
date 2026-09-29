#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
void print(Node *head) {
    for (Node *p = head->next; p != nullptr; p = p->next)
        cout << p->data << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
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
        int pos, x;
        cin >> pos >> x;
        if (pos < 1) {
            cout << "error\n";
            continue;
        }
        Node *p = head;
        for (int i = 1; i < pos && p != nullptr; ++i) {
            p = p->next;
        }
        if (p == nullptr) {
            cout << "error\n";
            continue;
        }
        p->next = new Node{x, p->next};
        print(head);
    }
    for (int t = 0; t < 2; ++t) {
        int pos;
        cin >> pos;
        if (pos < 1) {
            cout << "error\n";
            continue;
        }
        Node *p = head;
        for (int i = 1; i < pos && p->next != nullptr; ++i) {
            p = p->next;
        }
        if (p->next == nullptr) {
            cout << "error\n";
            continue;
        }
        Node *q = p->next;
        p->next = q->next;
        delete q;
        print(head);
    }
    for (int t = 0; t < 2; ++t) {
        int pos;
        cin >> pos;
        if (pos < 1) {
            cout << "error\n";
            continue;
        }
        Node *p = head->next;
        for (int i = 1; i < pos && p != nullptr; ++i) {
            p = p->next;
        }
        if (p == nullptr) {
            cout << "error\n";
            continue;
        }
        cout << p->data << '\n';
    }
    return 0;
}