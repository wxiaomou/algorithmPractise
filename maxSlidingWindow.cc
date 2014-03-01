#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
	public:
		vector<int> foo(int A[], int n, int k) {
			if (!n && !k) return vector<int>();
			vector<int> ret;
			deque<int> Q;
			for (int i = 0; i < k; i++) {
				while(!Q.empty() && A[Q.back()] <= A[i])
					Q.pop_back();
				Q.push_back(i);
			}
			ret.push_back(A[Q.front()]);
			for (int i = k; i < n; i++) {
				while(!Q.empty() && A[Q.back()] <= A[i])
					Q.pop_back();
				Q.push_back(i);
				while(!Q.empty() && Q.front() < i - k)
					Q.pop_front();
				ret.push_back(A[Q.front()]);
			}
			return ret;
		}

};


int main() {
	Solution sol;
	//int A[8] = {1, 3, -1, -3, 5, 3, 6, 7};
	//vector<int> ret = sol.foo(A, 8, 3);
	int A[9] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	vector<int> ret = sol.foo(A, 9, 3);
	for (auto it = ret.begin(); it != ret.end(); it++)
		cout << *it << " ";
	cout << endl;
}
