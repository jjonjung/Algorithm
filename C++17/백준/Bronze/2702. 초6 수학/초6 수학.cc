#include <iostream>
using namespace std;

long long aa(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long a, b;
        cin >> a >> b;

        long long g = aa(a, b);
        long long l = (a * b) / g;

        cout << l << " " << g << "\n";
    }

    return 0;
}
