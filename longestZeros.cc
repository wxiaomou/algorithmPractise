#include <iostream>
using namespace std;

class Solution {
public:
	int longestZeros(int x) {
		if (!x) return 0;
		int len = 0;
		while (x) {
			int cnt = 0;
			if ((x & 1) == 0) {
				while ((x & 1) == 0) {	
					x >>= 1;
					cnt++;
				}
				len = max(cnt, len);
			} else {
				x >>= 1;
			}
		}
		return len;
	}
};

int main() {
	Solution sol;
	cout << sol.longestZeros(133) << endl;
	cout << sol.longestZeros(15) << endl;
	return 0;
}
