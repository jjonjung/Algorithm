#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    int start, end;
    cin >> start >> end;

    vector<long long> dist(N + 1, INF);
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur]) continue;
        if (cur == end) break;

        for (auto [next, w] : graph[cur]) {
            long long nextCost = cost + w;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    cout << dist[end] << '\n';
    return 0;
}
