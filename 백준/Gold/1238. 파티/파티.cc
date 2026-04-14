#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, M, X;
vector<pair<int,int>> adj[1001];
vector<pair<int,int>> rev[1001];

vector<int> dijkstra(int start, vector<pair<int,int>> graph[]) {
    vector<int> dist(N+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [next, weight] : graph[now]) {
            int nextCost = cost + weight;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    return dist;
}

int main() {
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;

        adj[u].push_back({v, t});
        rev[v].push_back({u, t}); // 역방향 그래프
    }

    vector<int> distFromX = dijkstra(X, adj); // X → i
    vector<int> distToX   = dijkstra(X, rev); // i → X

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, distFromX[i] + distToX[i]);
    }

    cout << answer;
}