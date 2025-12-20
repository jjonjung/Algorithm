#include <iostream>
using namespace std;

int main() {
    int N, arr[1001];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}