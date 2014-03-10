#include<iostream>
#include<vector>

using namespace std;
class Solution {
	public:
		int LCM(string A, string B) {
			int m = A.length();
			int n = B.length();
			vector<int> tmp(n + 1, 0);
			vector<vector<int>> dp(m + 1, tmp);
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
					else dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
				}
			}
			return dp[m][n];
		}

};


int main() {
	string A = "AGGTAB";
	string B = "GXTXAYB";
	Solution sol;
	cout << sol.LCM(A, B) << endl;
	string C = "BDCABA";
	string D = "ABCBDAB";
	cout << sol.LCM(C, D) << endl;
}
