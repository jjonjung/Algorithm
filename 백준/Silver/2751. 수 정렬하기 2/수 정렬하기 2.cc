#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());  // O(N log N)

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
