#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    long long K;
    std::cin >> N >> K;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) std::cin >> A[i];

    long long cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        cnt += K / A[i];
        K %= A[i];
        if (K == 0) break;
    }

    std::cout << cnt << '\n';
    return 0;
}
