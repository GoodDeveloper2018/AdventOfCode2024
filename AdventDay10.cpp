#include <bits/stdc++.h>
using namespace std;

// Instead of a vector<int>, use static arrays to avoid modern expansions:
static const int DR[4] = { -1,  1,  0, 0 };
static const int DC[4] = {  0,  0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    
    // 1) Read input until EOF
    while (true) {
        if (!getline(cin, line))
            break;  // Stop if no more input
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    // 2) Build the heightMap
    int rows = (int)lines.size();
    int cols = (rows > 0) ? (int)lines[0].size() : 0;

    vector<vector<int>> heightMap(rows, vector<int>(cols));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            heightMap[r][c] = lines[r][c] - '0'; // convert '0'..'9' to 0..9
        }
    }

    long long totalScore = 0;

    // 3) For each cell, check if it's a trailhead (height == 0).
    //    Then do BFS to find reachable 9's by +1 stepping.
    for (int startR = 0; startR < rows; startR++) {
        for (int startC = 0; startC < cols; startC++) {
            if (heightMap[startR][startC] == 0) {
                
                // We'll do a BFS from this (startR, startC)
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                set<pair<int,int>> foundNines;  // track distinct 9-cells found

                queue<pair<int,int>> q;
                q.push( make_pair(startR, startC) );
                visited[startR][startC] = true;

                while (!q.empty()) {
                    // old-style "pop front and unpack the pair"
                    pair<int,int> frontCell = q.front();
                    q.pop();

                    int cr = frontCell.first;
                    int cc = frontCell.second;

                    // If current cell is a 9, record it
                    if (heightMap[cr][cc] == 9) {
                        foundNines.insert( make_pair(cr, cc) );
                    }

                    // Check four neighbors
                    for (int i = 0; i < 4; i++) {
                        int nr = cr + DR[i];
                        int nc = cc + DC[i];
                        // Bounds check
                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                            continue;
                        // Not visited?
                        if (!visited[nr][nc]) {
                            // Only move if neighbor's height == current + 1
                            if (heightMap[nr][nc] == heightMap[cr][cc] + 1) {
                                visited[nr][nc] = true;
                                q.push( make_pair(nr, nc) );
                            }
                        }
                    }
                }

                // Score of this trailhead = number of distinct 9-cells found
                long long score = (long long)foundNines.size();
                totalScore += score;
            }
        }
    }

    // 4) Print the total score for all trailheads
    cout << totalScore << "\n";
    return 0;
}
