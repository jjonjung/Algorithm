#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<bool> isPrime(N + 1, true);
    if (N >= 0) isPrime[0] = false;
    if (N >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    int minPrime = -1;
    long long sum = 0;

    for (int x = M; x <= N; ++x) {
        if (isPrime[x]) {
            sum += x;
            if (minPrime == -1) minPrime = x;
        }
    }

    if (minPrime == -1) {
        cout << -1 << '\n';
    } else {
        cout << sum << '\n' << minPrime << '\n';
    }

    return 0;
}
