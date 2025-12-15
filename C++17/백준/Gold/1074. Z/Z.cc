#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int ans = 0;

void solve(int n, int y, int x) {
    if (n == 0) {
        cout << ans << "\n";
        return;
    }

    int half = 1 << (n - 1);
    
    int area = half * half;

    if (r < y + half && c < x + half) {
        solve(n - 1, y, x);
    }
    else if (r < y + half && c >= x + half) {
        ans += area;
        solve(n - 1, y, x + half);
    }
    else if (r >= y + half && c < x + half) {
        ans += area * 2; 
        solve(n - 1, y + half, x);
    }
    else {
        ans += area * 3; 
        solve(n - 1, y + half, x + half);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r >> c;
  
    solve(N, 0, 0);

    return 0;
}