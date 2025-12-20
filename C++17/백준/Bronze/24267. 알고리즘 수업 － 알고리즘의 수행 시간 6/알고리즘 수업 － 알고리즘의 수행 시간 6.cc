#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long count = (n * (n - 1) * (n - 2)) / 6;

    cout << count << "\n";
    cout << 3 << endl;

    return 0;
}