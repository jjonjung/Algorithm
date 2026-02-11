#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> cards(N);
    for(int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    int M;
    cin >> M;

    while(M--) {
        int query;
        cin >> query;

        int count = upper_bound(cards.begin(), cards.end(), query)
                  - lower_bound(cards.begin(), cards.end(), query);

        cout << count << " ";
    }

    return 0;
}
