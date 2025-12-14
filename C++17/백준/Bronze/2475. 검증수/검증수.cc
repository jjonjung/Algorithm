#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> x;
        sum += x * x;
    }

    cout << sum % 10 << '\n';
    return 0;
}
