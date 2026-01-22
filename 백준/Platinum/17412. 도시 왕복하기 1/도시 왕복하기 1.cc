#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int rev;   
    int cap;  
};

struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;

    Dinic(int n) : N(n), G(n), level(n), it(n) {}

    void addEdge(int fr, int to, int cap) {
        Edge a{to, (int)G[to].size(), cap};
        Edge b{fr, (int)G[fr].size(), 0};
        G[fr].push_back(a);
        G[to].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (const auto &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = it[v]; i < (int)G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] == level[v] + 1) {
                int ret = dfs(e.to, t, min(f, e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    G[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (true) {
                int pushed = dfs(s, t, 1e9);
                if (!pushed) break;
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    cin >> N >> P;

    Dinic dinic(N);

    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        dinic.addEdge(u, v, 1);
    }

    int s = 0;  
    int t = 1;  

    cout << dinic.maxFlow(s, t) << "\n";
    return 0;
}
