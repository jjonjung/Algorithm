#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a1, a0;
    long long c, n0;
    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    if (a1 > c) {
        cout << 0 << '\n';
        return 0;
    }

    long long left = a1 * n0 + a0;
    long long right = c * n0;

    cout << (left <= right ? 1 : 0) << '\n';
    return 0;
}
