#include<iostream>

using namespace std;

class Solution {
	public:
		int find(int A[], int n) {
			int cnt = 0, cur = 0;
			for (int i = 0; i < n; i++) {
				if (cnt == 0) {
					cur = A[i];
					cnt = 1;
				}
				if (cur == A[i]) {
					cnt++;
				} else {
					cnt--;
				}
			}
			cnt = 0;
			for (int i = 0; i < n; i++) {
				if (A[i] == cur)
					cnt ++;
			}
			if (cnt > n / 2)
				return cur;
			else 
				return -1;
		}
};

int main() {
	Solution sol;
	int A[] = {1, 1, 2, 3, 4, 1, 6, 1, 7, 1, 1};
	cout << sol.find(A, 11) << endl;
	int B[] = {1, 2, 3, 7, 6, 1, 7, 1, 1};
	cout << sol.find(B, 9) << endl;
}
