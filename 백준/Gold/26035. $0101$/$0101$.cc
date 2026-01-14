#include <iostream>
using namespace std;

static const long long C = 1000000007LL;
// a^e % C
long long Ca(long long a, long long e) {
    long long r = 1LL % C;
    a %= C;

    while (e > 0) {
        if (e & 1LL) r = (r * a) % C;
        a = (a * a) % C;
        e >>= 1LL;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    long long powA = Ca(2LL, A);
    long long powB = Ca(2LL, B);

    long long ans = (powA + powB - 2LL) % C;
    if (ans < 0) ans += C;

    cout << ans << '\n';
    return 0;
}
