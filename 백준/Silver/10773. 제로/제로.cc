#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    stack<int> st;
    long long sum = 0;

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            sum -= st.top();
            st.pop();
        } else {
            st.push(x);
            sum += x;
        }
    }

    cout << sum << '\n';
    return 0;
}
