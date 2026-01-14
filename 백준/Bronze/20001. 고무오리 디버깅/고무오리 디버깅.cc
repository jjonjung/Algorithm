#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    int cnt = 0; 

    while (getline(cin, s)) {
        if (s == "고무오리 디버깅 끝") break;

        if (s == "문제") {
            cnt++;
        } else if (s == "고무오리") {
            if (cnt > 0) cnt--;
            else cnt += 2;
        }
    }

    if (cnt == 0) cout << "고무오리야 사랑해\n";
    else cout << "힝구\n";

    return 0;
}
