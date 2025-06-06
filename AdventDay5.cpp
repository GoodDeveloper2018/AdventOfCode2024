/* REDACTED I DON'T WANT TO DO THIS IN C++ BECAUSE I EXCEED RUNTIME AND IDK WHY*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> initials(T), afters(T);
    for (int i = 0; i < T; i++) {
        string ruleLine;
        cin >> ruleLine;

        char delimiter = '|';
        size_t pos = ruleLine.find(delimiter);
        int xVal = stoi(ruleLine.substr(0, pos));
        int yVal = stoi(ruleLine.substr(pos + 1));
        initials[i] = xVal;
        afters[i] = yVal;
    }

    long long sumOfMiddles = 0;
    int correctUpdatesCount = 0;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        string line;
        if (!getline(cin, line)) {
            break;
        }
        if (line.empty()) {
            continue;
        }

        vector<int> updatePages;
        {
            stringstream ss(line);
            while (ss.good()) {
                string token;
                if (!getline(ss, token, ',')) break;
                updatePages.push_back(stoi(token));
            }
        }

        if (updatePages.empty()) {
            continue;
        }

        unordered_map<int, int> indexOf;
        for (int i = 0; i < (int)updatePages.size(); i++) {
            indexOf[updatePages[i]] = i;
        }

        bool isCorrect = true;
        for (int i = 0; i < T; i++) {
            int xVal = initials[i];
            int yVal = afters[i];
            if (indexOf.find(xVal) != indexOf.end() && indexOf.find(yVal) != indexOf.end()) {
                if (indexOf[xVal] >= indexOf[yVal]) {
                    isCorrect = false;
                    break;
                }
            }
        }

        if (isCorrect) {
            correctUpdatesCount++;
            int n = (int)updatePages.size();
            int midIndex = n / 2;
            sumOfMiddles += updatePages[midIndex];
        }
    }

    cout << sumOfMiddles << "\n";
    return 0;
}
