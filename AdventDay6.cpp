#include <bits/stdc++.h>
using namespace std;

static const int direction_row[4] = {-1, 0, 1, 0};
static const int direction_column[4] = {0, 1, 0, -1};

// Rotates the direction 90 degrees to the right
int turnRight(int dir) {
    return (dir + 1) % 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the entire map
    vector<string> grid;
    {
        string line;
        while (true) {
            if (!getline(cin, line)) break;
            if (!line.empty()) {
                grid.push_back(line);
            } else {
            }
        }
    }

    if (grid.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    int rows = (int)grid.size();
    int cols = (int)grid[0].size();

    // Find guard starting position and direction
    int startR = -1, startC = -1;
    int dir = -1; // 0=Up, 1=Right, 2=Down, 3=Left

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            char ch = grid[r][c];
            if (ch == '^') {
                startR = r; startC = c; dir = 0;
            } else if (ch == '>') {
                startR = r; startC = c; dir = 1;
            } else if (ch == 'v') {
                startR = r; startC = c; dir = 2;
            } else if (ch == '<') {
                startR = r; startC = c; dir = 3;
            }
            if (dir != -1) {
                // Replace guard symbol with '.' for easier obstacle checks
                grid[r][c] = '.';
                break;
            }
        }
        if (dir != -1) break;
    }

    // If no guard found, answer is 0
    if (dir == -1) {
        cout << 0 << "\n";
        return 0;
    }

    // Set of visited positions
    set<pair<int,int>> visited;
    // Current position
    int guardirection_row = startR;
    int guardirection_column = startC;

    // Mark the start as visited
    visited.insert({guardirection_row, guardirection_column});

    while (true) {
        int nr = guardirection_row + direction_row[dir];
        int nc = guardirection_column + direction_column[dir];

        bool obstacle = false;
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
            break;
        }
        if (grid[nr][nc] == '#') {
            // There an obstacle
            obstacle = true;
        }

        if (obstacle) {
            // Turn right
            dir = turnRight(dir);
        } else {
            // Move forward
            guardirection_row = nr;
            guardirection_column = nc;
            visited.insert({guardirection_row, guardirection_column});
        }
    }

    // Number of distinct visited positions
    cout << visited.size() << "\n";
    return 0;
}
