#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

//다익스트라는 우선순위 큐 기반
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    int K;
    cin >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    const int INF = numeric_limits<int>::max();
    vector<int> dist(V + 1, INF);
    dist[K] = 0;

    // (거리, 정점) → 최소 힙
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push(make_pair(0, K));

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode]) continue;

        for (size_t i = 0; i < graph[currentNode].size(); i++) {
            int nextNode = graph[currentNode][i].first;
            int weight   = graph[currentNode][i].second;

            if (dist[nextNode] > currentDist + weight) {
                dist[nextNode] = currentDist + weight;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}
