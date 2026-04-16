#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int M;
    cin >> M;

    stack<char> left, right;

    for (char c : str) {
        left.push(c);
    }

    while (M--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        }
        else if (cmd == 'P') {
            char x;
            cin >> x;
            left.push(x);
        }
    }

    string result;

    while (!left.empty()) {
        result += left.top();
        left.pop();
    }
    reverse(result.begin(), result.end());

    while (!right.empty()) {
        result += right.top();
        right.pop();
    }

    cout << result;
}