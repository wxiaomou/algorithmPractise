//http://www.careercup.com/question?id=9167198
#include<iostream>
#include<vector>

using namespace std;

class nums {
public:
	int get(vector<int> input) {
		int n = input.size();
		if (n < 2 || n % 2 != 0) return -1;
		//int cnt = 1;
		int cur = input[0];
		for (int i = 1; i < n; i++) {
			if (input[i] == cur) return cur;
			cur = input[i];
		}
		for (int i = n - 1; i > n - 5; i--) {
			int cur = input[i];
			for (int j = i - 1; j > n - 5; j--) {
				if (input[i] == cur) return cur;
			}	
		}
		return -1;
	}
	
};

int main() {
	vector<int> input;
	int tmp;
	while (cin >> tmp) input.push_back(tmp);
	nums _tmp;
	cout << _tmp.get(input) << endl;
}
