#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> order(N);
    for (int i = 0; i < N; i++) {
        cin >> order[i];
    }

    if (order[0] != 1) {
        cout << 0;
        return 0;
    }

    vector<int> pos(N + 1);
    for (int i = 0; i < N; i++) {
        pos[order[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), [&](int a, int b) {
            return pos[a] < pos[b];
        });
    }

    vector<int> result;
    vector<bool> visited(N + 1, false);
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push_back(cur);

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (result[i] != order[i]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}