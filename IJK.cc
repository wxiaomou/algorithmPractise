#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
	public:
		void find(int A[], int n) {
				if (n < 3) return;
				int lmin[n], Rmax[n];
				lmin[0] = A[0];
				for (int i = 1; i < n; i++) {
					lmin[i] = min(lmin[i - 1], A[i]);
				}
				Rmax[n - 1] = A[n - 1];
				for (int i = n - 2; i >= 0; i--) {
					Rmax[i] = max(Rmax[i + 1], A[i]);
				}

				for (int i = 1; i < n - 1; i++) {
					if (lmin[i] < A[i] && A[i] < Rmax[i]) {
						cout << lmin[i] << " " << A[i] << " " << Rmax[i] << endl;
					}
				}
		}
		/*
		 * 
		 * O(1) space solution, key, find i, j first, if possible update j so let A[j] still larger then A[i] but small the older A[j] so that easy to find A[k];
		 * if find a pair A[i'] < A[j'] which A[i'] < A[i] and A[j'] < A[j] then update the pair in order to easy find A[k]; 
		 */
		void find2(int A[], int n) {
			if (n < 3) return;
			int i = -1, j = -1, k = -1, tmp = -1;

			for (int p = 0; p < n; p++) {
				if (i == -1) {
					i = p;
				} else {
					if (j == -1) {
						if (A[p] > A[i]) {
							j = p;
						} else {
							i = p;
						}
					} else {
						if (A[p] > A[j]) {
							cout << A[i] << " " << A[j] << " " << A[p] << endl;
							return;
						} else if (A[p] < A[j]) {
							if (tmp == -1) {
								if (A[p] > A[i])
									j = p;
								else 
									tmp = p;
							} else {
								if (A[p] > A[tmp]) {
									i = tmp; 
									j = p;
									tmp = -1;
								} else {
									tmp = p;
								}
							}
							
							}
						}
					}
				}
		}
};

int main() {
	Solution sol;
	int A[9] = {4,7,5,1,3,8,9,6,2};
	//sol.find(A, 9);
	int B[9] = {4, 7, 5, 1, 3, 8, 9, 6, 2};
	sol.find2(B, 9);
}
