#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visited[1001];

void DFS(int node)
{
    visited[node] = true;
    cout << node << ' ';

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            DFS(next);
        }
    }
}

void BFS(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int next : graph[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);

    cout << '\n';

    fill(visited, visited + 1001, false);

    BFS(V);

    return 0;
}