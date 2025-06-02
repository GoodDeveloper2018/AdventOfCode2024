#include <bits/stdc++.h>
using namespace std;	
void partOne() {
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
        if (input.empty()) {
        	continue;
        }
        
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
}

void partTwo() {
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

        bool increasing = true, decreasing = true, valid = true;
        for (size_t j = 1; j < input.size(); ++j) {
            int diff = input[j] - input[j - 1];
            if (!(abs(diff) >= 1 && abs(diff) <= 3)) {
                valid = false;
                break;
            }
            if (input[j] > input[j - 1]) decreasing = false;
            if (input[j] < input[j - 1]) increasing = false;
        }
        if (valid && (increasing || decreasing)) {
            solution++;
            continue;
        }

        bool fixed = false;
        for (int remove = 0; remove < input.size(); remove++) {
            vector<int> temp;
            for (int j = 0; j < input.size(); j++) {
                if (j != remove) temp.push_back(input[j]);
            }

            bool inc = true, dec = true, ok = true;
            for (int j = 1; j < temp.size(); j++) {
                int diff = temp[j] - temp[j - 1];
                if (!(abs(diff) >= 1 && abs(diff) <= 3)) {
                    ok = false;
                    break;
                }
                if (temp[j] > temp[j - 1]) dec = false;
                if (temp[j] < temp[j - 1]) inc = false;
            }

            if (ok && (inc || dec)) {
                solution++;
                fixed = true;
                break;
            }
        }
    }

    cout << solution << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //Can only run one part per execution because partOne calls get line until end of input
    //When partTwo() tries getline(cin, line); --> fails and outer loop breaks so solution = 0 from initialization 
    
    //partOne();
    partTwo();
    
    return 0;
}
