#include <bits/stdc++.h>
using namespace std;

int main () {
	//Only to make code run faster for larger input
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> left_list;
    vector<int> right_list;
    
    int left, right;
    
    while (cin >> left >> right) {
        left_list.push_back(left);
        right_list.push_back(right);
    }

    unordered_map<int, int> frequency_map;
    for (const int& num : right_list) {
        frequency_map[num]++;
    }
    
    long long similarity_score = 0;
    for (const int& num : left_list) {
        similarity_score += static_cast<long long>(num) * frequency_map[num];
    }
    
    cout << similarity_score << "\n";
    
    return 0;
}
