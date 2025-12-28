#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for (auto& p : lines) {
        cin >> p.first >> p.second;
    }

    sort(lines.begin(), lines.end());

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = lines[i].second;
    }

    vector<int> dp;
    for (int x : b) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << n - dp.size() << '\n';
    return 0;
}
