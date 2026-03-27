#include <iostream>

int main() {
    int K;
    std::cin >> K;

    int stack[100000];
    int top = -1;

    for (int i = 0; i < K; i++) {
        int x;
        std::cin >> x;

        if (x == 0) {
            top--; // pop
        } else {
            top++;
            stack[top] = x; // push
        }
    }

    long long sum = 0;

    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }

    std::cout << sum << std::endl;

    return 0;
}