#include <iostream>
#include <string>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    int result = A * B * C;

    int count[10] = {0};

    std::string s = std::to_string(result);

    for (int i = 0; i < s.length(); i++) {
        int digit = s[i] - '0';
        count[digit]++;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << count[i] << '\n';
    }

    return 0;
}