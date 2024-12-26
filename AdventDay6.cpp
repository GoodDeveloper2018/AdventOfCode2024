#include <bits/stdc++.h>
using namespace std;

// Directions encoded as 0=Up, 1=Right, 2=Down, 3=Left.
static const int DR[4] = {-1, 0, 1, 0};
static const int DC[4] = {0, 1, 0, -1};

// Rotates the direction 90 degrees to the right
int turnRight(int dir) {
    return (dir + 1) % 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the entire map (grid) until EOF.
    vector<string> grid;
    {
        string line;
        while (true) {
            if (!getline(cin, line)) break;
            if (!line.empty()) {
                grid.push_back(line);
            } else {
                // If you want to include empty lines as part of the map, 
                // uncomment the next line. Otherwise, skip them.
                // grid.push_back("");
            }
        }
    }

    if (grid.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    int rows = (int)grid.size();
    int cols = (int)grid[0].size();

    // Find guard's starting position and direction
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
    int guardR = startR;
    int guardC = startC;

    // Mark the start as visited
    visited.insert({guardR, guardC});

    while (true) {
        // 1) Check if obstacle is in front or out of bounds
        int nr = guardR + DR[dir];
        int nc = guardC + DC[dir];

        bool obstacle = false;
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
            // Next step is out of the map -> guard leaves
            break;
        }
        if (grid[nr][nc] == '#') {
            // There's an obstacle
            obstacle = true;
        }

        if (obstacle) {
            // Turn right
            dir = turnRight(dir);
        } else {
            // Move forward
            guardR = nr;
            guardC = nc;
            visited.insert({guardR, guardC});
        }
    }

    // Number of distinct visited positions
    cout << visited.size() << "\n";
    return 0;
}
