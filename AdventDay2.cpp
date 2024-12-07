#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int lines = 1000;
    int solution = 0;

    for (int i = 0; i < lines; i++) {
        vector<int> input;
        string line;
        if (!getline(cin, line)) break; 
        if (line.empty()) continue; 

        int x;
        stringstream ss(line);
        while (ss >> x) {
            input.push_back(x);
        }

        if (input.empty()) continue;
        
        bool increasing = true, decreasing = true;
        for (size_t j = 1; j < input.size(); ++j) {
            int diff = input[j] - input[j - 1];
            
            if (!((diff >= 1 && diff <= 3) || (diff <= -1 && diff >= -3))) {
                increasing = decreasing = false;
                break;
            }

            if (input[j] > input[j - 1]) decreasing = false;
            if (input[j] < input[j - 1]) increasing = false;
        }

        if (increasing || decreasing) {
            solution++;
        }
    }

    cout << solution << "\n";
    return 0;
}
