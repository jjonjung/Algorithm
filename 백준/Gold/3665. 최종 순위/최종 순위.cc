#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> last(n);
        for (int i = 0; i < n; i++) cin >> last[i];

        vector<vector<char>> adj(n + 1, vector<char>(n + 1, 0));
        vector<int> indeg(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int u = last[i];
            for (int j = i + 1; j < n; j++) {
                int v = last[j];
                adj[u][v] = 1;
            }
        }

        for (int u = 1; u <= n; u++) {
            int d = 0;
            for (int v = 1; v <= n; v++) {
                if (adj[v][u]) d++;
            }
            indeg[u] = d;
        }

        int m;
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;

            if (adj[a][b]) {
                adj[a][b] = 0;
                adj[b][a] = 1;
                indeg[b]--;
                indeg[a]++; 
            } else {
                adj[b][a] = 0;
                adj[a][b] = 1;
                indeg[a]--; 
                indeg[b]++; 
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> result;
        bool ambiguous = false;

        for (int step = 0; step < n; step++) {
            if (q.empty()) break;          
            if ((int)q.size() > 1) ambiguous = true; 

            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v = 1; v <= n; v++) {
                if (adj[u][v]) {
                    adj[u][v] = 0;
                    indeg[v]--;
                    if (indeg[v] == 0) q.push(v);
                }
            }
        }

        if ((int)result.size() != n) {
            cout << "IMPOSSIBLE\n";
        } else if (ambiguous) {
            cout << "?\n";
        } else {
            for (int i = 0; i < n; i++) {
                if (i) cout << ' ';
                cout << result[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
