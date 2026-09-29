#include <bits/stdc++.h>
using namespace std;
struct Node {
    int id;
    Node *next;
};
int t, N, K, S;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> N >> K >> S;
        Node *pool = new Node[N + 1];
        for (int i = 1; i < N; ++i) {
            pool[i].id = i;
            pool[i].next = &pool[i + 1];
        }
        pool[N].id = N;
        pool[N].next = &pool[1];
        Node *pre = S > 1 ? &pool[S - 1] : &pool[N];
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j < K; ++j) pre = pre->next;
            Node *cur = pre->next;
            cout << cur->id << (i < N ? ' ' : '\n');
            pre->next = cur->next;
        }
        delete[] pool;
    }
    return 0;
}
