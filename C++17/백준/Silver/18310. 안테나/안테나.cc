#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    cout << houses[(n - 1) / 2] << "\n";

    return 0;
}