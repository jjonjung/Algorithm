#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<bool> isPrime(N + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}