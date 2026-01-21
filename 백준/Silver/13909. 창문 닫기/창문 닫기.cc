#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    std::cin >> N;

    long long r = static_cast<long long>(std::sqrt(static_cast<long double>(N)));

    while ((r + 1) * (r + 1) <= N) ++r;
    while (r * r > N) --r;

    std::cout << r << "\n";
    return 0;
}
