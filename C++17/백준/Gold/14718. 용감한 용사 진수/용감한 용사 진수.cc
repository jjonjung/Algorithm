#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;

struct Soldier {
    int h, a, i;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<Soldier> enemies(N);
    set<int> cand_h, cand_a, cand_i;

    for (int j = 0; j < N; j++) {
        cin >> enemies[j].h >> enemies[j].a >> enemies[j].i;
        cand_h.insert(enemies[j].h);
        cand_a.insert(enemies[j].a);
        cand_i.insert(enemies[j].i);
    }

    vector<int> all_h(cand_h.begin(), cand_h.end());
    vector<int> all_a(cand_a.begin(), cand_a.end());
    vector<int> all_i(cand_i.begin(), cand_i.end());

    ll answer = LLONG_MAX;

    for (int h : all_h) {
        for (int a : all_a) {
            for (int i : all_i) {
                int cnt = 0;
                for (const auto& e : enemies) {
                    if (h >= e.h && a >= e.a && i >= e.i) {
                        cnt++;
                    }
                }
                if (cnt >= K) {
                    ll cost = (ll)h + a + i;
                    if (cost < answer) answer = cost;
                }
            }
        }
    }

    if (answer == LLONG_MAX) {
        cout << "-1\n";
    } else {
        cout << answer << "\n";
    }

    return 0;
}