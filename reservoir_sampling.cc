//http://www.geeksforgeeks.org/reservoir-sampling/
#include<iostream>
#include<vector>
#include<random>

using namespace std;

class Solution {
	public:
		vector<int> random(int A[], int k) {
			if (A[0] == -1) return vector<int>(); //use -1 as the end of the input.
			vector<int> ret;
			int i = 0; 
			while (A[i] != -1) {
				if (ret.size() < k)
					ret.push_back(A[i]);
				else {
					int j = rand() % (i + 1);
					if (j < k)
						ret[j] = A[i];
				}
				i++;
			}
			return ret;
		}
};


int main() {
	Solution sol;
	int A[] = {1, 4, 6, 16, 3, 62, 3, 0, 5, 9, -1};
	vector<int> ret = sol.random(A, 3);
	for (auto it = ret.begin(); it != ret.end(); it++) cout << *it << " ";
	cout << endl;
  ret = sol.random(A, 5);
	for (auto it = ret.begin(); it != ret.end(); it++) cout << *it << " ";
	cout << endl;

}
