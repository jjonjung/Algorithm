#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    int K;
    cin >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> dist(V + 1, INF);
    dist[K] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, K});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curDist > dist[curNode]) continue;

        for (auto& next : graph[curNode]) {
            int nextNode = next.first;
            int weight = next.second;
            int newDist = curDist + weight;

            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}