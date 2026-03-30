#include <iostream>
#include <vector>

int n, m;
std::vector<int> graph[101];
bool visited[101];
int cnt = 0;

void dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];

        if (!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main() {
    std::cin >> n;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    std::cout << cnt;

    return 0;
}