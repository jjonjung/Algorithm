#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    map<string, int> bookCount; 

    for (int i = 0; i < N; i++) {
        string title;
        cin >> title;
        bookCount[title]++; 
    }

    int maxCount = 0;
    string answer = "";

    for (auto it = bookCount.begin(); it != bookCount.end(); it++) {
        string title = it->first;
        int count = it->second;

        if (count > maxCount) {
            maxCount = count;
            answer = title;
        }
    }

    cout << answer << '\n';

    return 0;
}