#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) cin >> board[i];

    int ans = 64; 

    for (int r = 0; r <= N - 8; r++) {
        for (int c = 0; c <= M - 8; c++) {

            int repaintW = 0; 
            int repaintB = 0; 

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    char cur = board[r + i][c + j];

                    char expectedW = ((i + j) % 2 == 0) ? 'W' : 'B';
                    char expectedB = ((i + j) % 2 == 0) ? 'B' : 'W';

                    if (cur != expectedW) repaintW++;
                    if (cur != expectedB) repaintB++;
                }
            }

            ans = min(ans, min(repaintW, repaintB));
        }
    }

    cout << ans << '\n';
    return 0;
}
