//http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class LIS {
public:
	int find(vector<int> input) {
		int n = input.size();
		if (n < 2) return 1;
		int L[n];
		for (int i = 0; i < n; i++) L[i] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (input[j] < input[i]) L[i] = max(L[i], L[j]  + 1);
			}
		}
		return L[n - 1];
	}

	int find2(vector<int> input) {
		int n = input.size();
		if (n < 2) return 1;
		int L[n];
		for (int i = 0; i < n; i++) L[i] = -1;
		recur(input, n - 1, L);
		return L[n - 1];
	}

	int recur(vector<int> &input, int index, int L[]) {
		if (index < 0) return 0;
		if (L[index] != -1) return L[index];
		for (int i = index - 1; i >= 0; i--) {
			if (input[index] > input[i]) L[index] = max(L[index], recur(input, i, L) + 1);
		}
		if (L[index] == -1) L[index] = 1; //!!!!!!!!!!!!!!!!!!!!!
		return L[index];
	}

};

int main() {
	LIS l;
	vector<int> input;
	int tmp;
	while (cin >> tmp) input.push_back(tmp);
	cout << l.find(input) << endl;
	cout << l.find2(input) << endl;

}
