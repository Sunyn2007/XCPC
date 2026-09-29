#include <bits/stdc++.h>
using namespace std;
struct Stu {
    string name;
    int room;
};
int n, m;
list<Stu> usedList;
list<int> freeList;
void assignRoom(string name) {
    int room = freeList.front();
    freeList.pop_front();
    auto it = usedList.begin();
    while (it != usedList.end() && it->room < room) ++it;
    usedList.insert(it, {name, room});
}
void returnRoom(int room) {
    for (auto it = usedList.begin(); it != usedList.end(); ++it) {
        if (it->room == room) {
            usedList.erase(it);
            break;
        }
    }
    freeList.push_back(room);
}
void showUsed() {
    bool first = true;
    for (const Stu &s : usedList) {
        if (!first) cout << '-';
        first = false;
        cout << s.name << '(' << s.room << ')';
    }
    cout << '\n';
}
void showFree() {
    bool first = true;
    for (int room : freeList) {
        if (!first) cout << '-';
        first = false;
        cout << room;
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Stu s;
        cin >> s.name >> s.room;
        usedList.push_back(s);
    }
    usedList.sort([](const Stu &a, const Stu &b) { return a.room < b.room; });
    for (int room = 101; room <= 120; ++room) {
        bool busy = false;
        for (const Stu &s : usedList)
            if (s.room == room) busy = true;
        if (!busy) freeList.push_back(room);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string op;
        cin >> op;
        if (op == "assign") {
            string name;
            cin >> name;
            assignRoom(name);
        } else if (op == "return") {
            int room;
            cin >> room;
            returnRoom(room);
        } else if (op == "display_used") {
            showUsed();
        } else if (op == "display_free") {
            showFree();
        }
    }
    return 0;
}
