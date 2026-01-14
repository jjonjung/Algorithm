#include <iostream>
using namespace std;

static const long long MOD = 1000000007LL;
// a^e % MOD
long long modpow(long long a, long long e) {
    long long r = 1LL % MOD;
    a %= MOD;

    while (e > 0) {
        if (e & 1LL) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1LL;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    long long powA = modpow(2LL, A);
    long long powB = modpow(2LL, B);

    long long ans = (powA + powB - 2LL) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
    return 0;
}
