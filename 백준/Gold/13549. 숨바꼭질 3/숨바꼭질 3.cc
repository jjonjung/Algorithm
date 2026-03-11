#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 200000;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> dist(MAX + 1, INF);
    deque<int> dq;

    dist[N] = 0;
    dq.push_front(N);

    while (!dq.empty()) {

        int cur = dq.front();
        dq.pop_front();

        if (cur == K) break;

        int next = cur * 2;
        if (next <= MAX && dist[next] > dist[cur]) {
            dist[next] = dist[cur];
            dq.push_front(next);
        }

        next = cur - 1;
        if (next >= 0 && dist[next] > dist[cur] + 1) {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }

        next = cur + 1;
        if (next <= MAX && dist[next] > dist[cur] + 1) {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }
    }

    cout << dist[K];

    return 0;
}