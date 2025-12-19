#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> x(n);
    vector<long long> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long mid_x = x[n / 2];
    long long mid_y = y[n / 2];

    long long total_distance = 0;
    for (int i = 0; i < n; i++) {
        total_distance += abs(x[i] - mid_x) + abs(y[i] - mid_y);
    }

    cout << total_distance << endl;

    return 0;
}