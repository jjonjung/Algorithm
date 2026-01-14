#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>
#include <cctype>

using namespace std;

static inline int ByteToInt(const string& tok) {
    return stoi(tok, nullptr, 16);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    // 1) "#define quadtree_width n"
    if (!getline(cin, line)) return 0;
    int n = 0;
    for (int i = (int)line.size() - 1; i >= 0; --i) {
        if (isdigit((unsigned char)line[i])) {
            int j = i;
            while (j >= 0 && isdigit((unsigned char)line[j])) --j;
            n = stoi(line.substr(j + 1, i - j));
            break;
        }
    }

    // 2) "#define quadtree_height n" (동일하므로 무시)
    getline(cin, line);

    // 3) "static char quadtree_bits[] = {"
    getline(cin, line);

    int bytesPerRow = n / 8;
    vector<vector<int>> a(n, vector<int>(n, 0)); // 0=W, 1=B

    for (int r = 0; r < n; ++r) {
        getline(cin, line);

        // 구분자 제거(토큰화 쉽게)
        for (char &c : line) {
            if (c == ',' || c == '{' || c == '}' || c == ';') c = ' ';
        }

        stringstream ss(line);
        vector<string> toks;
        string tok;
        while (ss >> tok) {
            if (tok.size() >= 3 && tok[0] == '0' && (tok[1] == 'x' || tok[1] == 'X'))
                toks.push_back(tok);
        }

        for (int b = 0; b < bytesPerRow; ++b) {
            int val = ByteToInt(toks[b]);
            // (LSB->MSB)
            for (int k = 0; k < 8; ++k) {
                int x = b * 8 + k;
                a[r][x] = (val & (1 << k)) ? 1 : 0; // 1이면 B(검정)
            }
        }
    }

    // 마지막 "};"
    getline(cin, line);

    // prefix sum (black count)
    vector<vector<int>> ps(n + 1, vector<int>(n + 1, 0));
    for (int y = 0; y < n; ++y) {
        int rowSum = 0;
        for (int x = 0; x < n; ++x) {
            rowSum += a[y][x];
            ps[y + 1][x + 1] = ps[y][x + 1] + rowSum;
        }
    }

    auto blackCount = [&](int x, int y, int sz) -> int {
        int x2 = x + sz, y2 = y + sz;
        return ps[y2][x2] - ps[y2][x] - ps[y][x2] + ps[y][x];
    };

    function<void(int,int,int,string&)> encode = [&](int x, int y, int sz, string &out) {
        int cnt = blackCount(x, y, sz);
        if (cnt == 0) { out.push_back('W'); return; }
        if (cnt == sz * sz) { out.push_back('B'); return; }

        out.push_back('Q');
        int h = sz / 2;
        // UL, UR, LL, LR
        encode(x,     y,     h, out);
        encode(x + h, y,     h, out);
        encode(x,     y + h, h, out);
        encode(x + h, y + h, h, out);
    };

    string out;
    out.reserve(n * n);

    cout << n << "\n";
    encode(0, 0, n, out);
    cout << out << "\n";
    return 0;
}
