#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> cards(N);
    for (int i = 0; i < N; ++i) std::cin >> cards[i];

    std::sort(cards.begin(), cards.end());

    int M;
    std::cin >> M;

    for (int i = 0; i < M; ++i) {
        int x;
        std::cin >> x;

        std::cout << (std::binary_search(cards.begin(), cards.end(), x) ? 1 : 0);
        if (i != M - 1) std::cout << ' ';
    }

    return 0;
}
