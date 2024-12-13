#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> grid;
    {
        string line;
        while (cin >> line) {
            grid.push_back(line);
        }
    }

    if (grid.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    int rows = (int)grid.size();
    int cols = (int)grid[0].size();

    string WORD = "XMAS";
    int word_len = (int)WORD.size();

    vector<int> dx = {0, 0, 1, -1,  1, -1, 1, -1};
    vector<int> dy = {1, -1, 0,  0,  1,  1, -1, -1};

    int countOccurrences = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == WORD[0]) {
                for (int d = 0; d < 8; d++) {
                    int nr = r, nc = c;
                    int i;
                    for (i = 1; i < word_len; i++) {
                        nr += dx[d];
                        nc += dy[d];
                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) break;
                        if (grid[nr][nc] != WORD[i]) break;
                    }
                    if (i == word_len) {
                        countOccurrences++;
                    }
                }
            }
        }
    }

    cout << countOccurrences << "\n";
    return 0;
}
