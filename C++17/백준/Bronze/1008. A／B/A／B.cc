#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A, B;
    cin >> A >> B;

    cout << fixed << setprecision(10) << A / B << '\n';
    return 0;
}
