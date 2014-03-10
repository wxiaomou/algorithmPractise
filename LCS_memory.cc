#include<iostream>
#include<vector>

using namespace std;
class Solution {
	public:
		int LCM(string A, string B) {
			int m = A.length();
			int n = B.length();
			vector<int> tmp(n, -1);
			vector<vector<int>> dp(m, tmp);
			_dp(A, B, 0, 0, dp);
			return dp[0][0];
		}

		int _dp(string &A, string &B, int i, int j, vector<vector<int>> &dp) {
			int m = A.length(), n = B.length();
			if (i == m || j == n) return 0;
			if (dp[i][j] != -1) return dp[i][j];
			if (A[i] == B[j]) {
				dp[i][j] =	_dp(A, B, i + 1, j + 1, dp) + 1;
				return dp[i][j];
			}

			dp[i][j] = max(_dp(A, B, i + 1, j, dp), _dp(A, B, i, j + 1, dp));
			return dp[i][j];
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
