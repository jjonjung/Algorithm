#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;
    vector<char> ops;
    int cur = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (cur <= x) {
            st.push(cur++);
            ops.push_back('+');
        }

        if (!st.empty() && st.top() == x) {
            st.pop();
            ops.push_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    for (char c : ops) {
        cout << c << '\n';
    }

    return 0;
}
