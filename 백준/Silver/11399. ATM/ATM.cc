#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    sort(P.begin(), P.end()); 

    long long sum = 0;   
    long long ans = 0;  
    for (int i = 0; i < N; i++) {
        sum += P[i];
        ans += sum;
    }

    cout << ans << '\n';
    return 0;
}
