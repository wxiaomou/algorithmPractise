//http://www.careercup.com/question?id=5724823657381888
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void reorder(vector<int> &input) {
		int n = input.size();
		if (!n) return;
		for (int i = 1; i < n; i++) {
			if (i % 2 == 0) {
				if (input[i] > input[i - 1]) {
					swap(input[i], input[i - 1]);
				}
			} else {
				if (input[i] < input[i - 1]) {
					swap(input[i], input[i - 1]);
				}
			}
		}
		return;
	}

	void reorder2(vector<int> &input) {
		int n = input.size();
		if (n < 2) return;
		sort(input.begin(), input.end());
		for (int i = 2; i < n; i += 2) {
			swap(input[i], input[i - 1]);
		}
		return;
	}
	
	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
};


int main() {
	vector<int> input;
	cout << "input distinct nums" << endl;
	int tmp;
	while (cin >> tmp) {
		input.push_back(tmp);
	}
	Solution sol;
	sol.reorder2(input);
	for (auto it = input.begin(); it != input.end(); it++) cout << *it << " ";
	cout << endl;
}
