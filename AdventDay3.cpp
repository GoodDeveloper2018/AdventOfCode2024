#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read entire input
    ostringstream oss;
    oss << cin.rdbuf();
    string input = oss.str();

    // Regex to match mul(X,Y) with X and Y as 1-3 digit numbers
    regex pattern(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\))");
    smatch match;

    long long total_sum = 0;

    // Search for all valid mul instructions
    string::const_iterator searchStart(input.cbegin());
    while (regex_search(searchStart, input.cend(), match, pattern)) {
        string num1_str = match[1].str();
        string num2_str = match[2].str();

        // Validate digits (optional, since regex ensures digits)
        bool valid1 = all_of(num1_str.begin(), num1_str.end(), ::isdigit);
        bool valid2 = all_of(num2_str.begin(), num2_str.end(), ::isdigit);

        if (valid1 && valid2) {
            int x = stoi(num1_str);
            int y = stoi(num2_str);
            total_sum += (long long)x * (long long)y;
        }

        searchStart = match.suffix().first;
    }

    cout << total_sum << "\n";
    return 0;
}
