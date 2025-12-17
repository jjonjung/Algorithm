#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int d = A * A - B;

    int s = 0;
    while (s * s < d) {
        s++;
    }

    int x1 = -A - s;
    int x2 = -A + s;

    if (x1 == x2) {
        cout << x1 << endl;
    }
    else {
        if (x1 < x2)
            cout << x1 << " " << x2 << endl;
        else
            cout << x2 << " " << x1 << endl;
    }

    return 0;
}
