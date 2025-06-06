#include <bits/stdc++.h>
using namespace std;

long long partOne() {
    vector<string> g;
    string line;
    while (cin >> line) g.push_back(line);

    if (g.empty()) return 0;
    int R = g.size(), C = g[0].size();
    const string WORD = "XMAS";
    const int L = WORD.size();

    int dx[8] = {0, 0, 1,-1, 1,-1, 1,-1};
    int dy[8] = {1,-1, 0, 0, 1, 1,-1,-1};

    long long cnt = 0;

    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (g[r][c] == WORD[0])
                for (int d = 0; d < 8; ++d) {
                    int nr = r, nc = c, i = 1;
                    for (; i < L; ++i) {
                        nr += dx[d];  nc += dy[d];
                        if (nr < 0 || nr >= R || nc < 0 || nc >= C) break;
                        if (g[nr][nc] != WORD[i]) break;
                    }
                    if (i == L) ++cnt;
                }
    return cnt;
}

long long partTwo() {
    vector<string> g;
    string line;
    while (cin >> line) g.push_back(line);

    if (g.empty()) return 0;
    int R = g.size(), C = g[0].size();
    long long cnt = 0;

    for (int r = 1; r < R - 1; ++r)
        for (int c = 1; c < C - 1; ++c)
            if (g[r][c] == 'A') {
                char nw = g[r - 1][c - 1],
                     ne = g[r - 1][c + 1],
                     sw = g[r + 1][c - 1],
                     se = g[r + 1][c + 1];

                bool diag1 = (nw == 'M' && se == 'S') || (nw == 'S' && se == 'M');
                bool diag2 = (ne == 'M' && sw == 'S') || (ne == 'S' && sw == 'M');

                if (diag1 && diag2) ++cnt;
            }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << partTwo() << endl;
    return 0;
}
