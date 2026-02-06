#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    deque<int> q;
    string cmd;

    while (N--) {
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            q.push_back(x);
        } else if (cmd == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        } else if (cmd == "back") {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }

    return 0;
}
