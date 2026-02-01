#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int arr[3] = {a, b, c};
    sort(arr, arr + 3); 

    int x = arr[0], y = arr[1], z = arr[2];

    if (x + y > z) {
        cout << x + y + z << '\n';
    } else {
        cout << 2 * (x + y) - 1 << '\n';
    }
    return 0;
}
