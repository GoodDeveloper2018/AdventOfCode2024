#include <bits/stdc++.h>
using namespace std;

void partOne() {
    ostringstream oss;
    oss << cin.rdbuf();
    string input = oss.str();

    // Regex to match mul(X,Y) with X and Y as 1-3 digit numbers
    regex pattern(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\))");
    
    long long total_sum = 0;
	smatch match;
	auto it = input.cbegin();
	
    while (regex_search(it, input.cend(), match, pattern)) {
		long long a = stoll(match[1]);
		long long b = stoll(match[2]);
		total_sum += a*b;
		it = match.suffix().first;
    }
    cout << total_sum << endl;
}

void partTwo() {
	ostringstream oss;
    oss << cin.rdbuf();
    string input = oss.str(); 
    
    regex pattern2(R"(\b(do\(\)|don't\(\)|mul\(([0-9]{1,3}),([0-9]{1,3})\)))");
    bool enabled = true;
    long long total = 0;
    smatch m;
    auto it = input.cbegin();
    
    while (regex_search(it, input.cend(), m, pattern2)) {
    	string t = m[0];
    	if (t == "do()") {
    		enabled = true;
    	}
    	else if (t == "don't()") {
    		enabled = false;
    	}
    	else if (enabled) {
    		long long a = stoll(m[2]);
    		long long b = stoll(m[3]);
    		total += a*b;
    	}
    	it = m.suffix().first;
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//partOne();
	partTwo();
	
    return 0;
}
