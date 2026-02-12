#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> lis;
    lis.reserve(N); 

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        auto it = lower_bound(lis.begin(), lis.end(), x);

        if (it == lis.end()) {
            lis.push_back(x); 
        } else {
            *it = x;  
        }
    }

    cout << lis.size();
    return 0;
}
