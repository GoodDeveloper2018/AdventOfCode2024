#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int lines = 1000;
	int solution = 0;
	for (int i = 0; i < lines; i++) {
		vector<int> input;
		while (true) {
			int x;
			scanf("%d", &x);
			input.push_back(x);
			char c;
			scanf("%c", &c);
			if (c == "\n") {
				break;
			}
		}
	}

	int k = input.size();
	cout << k << endl;
	bool only_increment;
	bool only_decrement;
    for (int j = 0; j < k; j++) {
        int diff = input[i+1] - input[i];
		int add = input[i+1] + input[i];
    }

	return 0;
}
