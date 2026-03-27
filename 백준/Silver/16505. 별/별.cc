#include <iostream>
#include <string>

const int MAX_SIZE = 2048;
char board[MAX_SIZE][MAX_SIZE];

void draw(int n, int x, int y) {
    if (n == 0) {
        board[x][y] = '*';
        return;
    }
    
    int half = (1 << n);        // 2^n
    int quarter = half / 2;     // 2^(n-1)
    
    draw(n - 1, x, y);
    draw(n - 1, x, y + quarter);
    draw(n - 1, x + quarter, y);
}

int main() {
    int N;
    std::cin >> N;
    
    int size = (1 << (N + 1));   // 2^(N+1)
    
    // board 초기화 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = ' ';
        }
    }
    
    // 호출 왼쪽 위 시작
    draw(N, 0, 0);
    
    // 각 줄 끝 불필요한 공백 제거
    for (int i = 0; i < size - 1; i++) {        // 높이 2^(N+1) - 1
        std::string line = "";
        for (int j = 0; j < size; j++) {
            line += board[i][j];
        }
        
        // 오른쪽 끝 공백 제거
        while (!line.empty() && line.back() == ' ') {
            line.pop_back();
        }
        
        std::cout << line << '\n';
    }
    
    return 0;
}