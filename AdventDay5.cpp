#include <bits/stdc++.h>
using namespace std;

long long partOne() {
    int T;
    if (!(cin >> T)) return 0;

    vector<int> X(T), Y(T);
    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;
        size_t bar = s.find('|');
        if (bar == string::npos) continue;
        int xVal = stoi(s.substr(0, bar));
        int yVal = stoi(s.substr(bar + 1));
        X[i] = xVal;
        Y[i] = yVal;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long sumMid = 0;
    string line;
    while (getline(cin, line)) {
        vector<int> pages;
        string token;
        stringstream ss(line);
        while (getline(ss, token, ',')) {
            if (token.empty()) continue;
            pages.push_back(stoi(token));
        }
        if (pages.empty()) continue;

        unordered_map<int, int> pos;
        for (int i = 0; i < (int)pages.size(); ++i) pos[pages[i]] = i;

        bool ok = true;
        for (int i = 0; i < T && ok; ++i)
            if (pos.count(X[i]) && pos.count(Y[i]) && pos[X[i]] >= pos[Y[i]]) ok = false;

        if (ok) sumMid += pages[pages.size() / 2];
    }
    return sumMid;
}

long long partTwo() {
    return partOne();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << partOne() << '\n';
    return 0;
}
