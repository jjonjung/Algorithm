#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

static const long long INF = (1LL << 60);

vector<long long> dijkstra(int start, const vector<vector<pair<int,int>>>& graph) {
    int n = (int)graph.size() - 1;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curD, u] = pq.top();
        pq.pop();

        if (curD != dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            long long nd = curD + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int,int>>> graph(N + 1);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    auto dist1  = dijkstra(1, graph);
    auto distV1 = dijkstra(v1, graph);
    auto distV2 = dijkstra(v2, graph);

    long long pathA = INF;
    long long pathB = INF;

    if (dist1[v1] < INF && distV1[v2] < INF && distV2[N] < INF) {
        pathA = dist1[v1] + distV1[v2] + distV2[N];
    }

    if (dist1[v2] < INF && distV2[v1] < INF && distV1[N] < INF) {
        pathB = dist1[v2] + distV2[v1] + distV1[N];
    }

    long long ans = min(pathA, pathB);
    if (ans >= INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}
