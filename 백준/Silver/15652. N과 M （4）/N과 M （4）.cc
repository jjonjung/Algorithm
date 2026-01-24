#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> seq;

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            if (i) cout << ' ';
            cout << seq[i];
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= N; i++) {
        seq[depth] = i;
        dfs(depth + 1, i); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    seq.assign(M, 0);

    dfs(0, 1);
    return 0;
}
