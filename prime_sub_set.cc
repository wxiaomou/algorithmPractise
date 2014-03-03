#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
	public:
		int find(int N) {
			if (N < 2) return 0;
			int S = (N + 1) * N / 2;
			vector<int> tmp(S + 1, 0);
			vector<vector<int>> dp(N + 1, tmp);
			dp[1][1] = 1;
			cout << 1 << " ";
			for (int j = 2; j <= S; j++) {
				dp[1][j] = 0;
				cout << dp[0][j] << " ";
			}
			cout << endl;

			for (int i = 2; i <= N; i++) {
				for (int j = 1; j <= S; j++) {
					if (j - i < 0) 
						dp[i][j] = dp[i - 1][j];
					else if (i == j)
						dp[i][j] = dp[i - 1][j] + 1;
					else
						dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
					cout << dp[i][j] << " ";
				}
				cout << endl;
			}

			int ans = 0;
			for (int j = 2; j <= S; j++)	{
				if (check_prime(j)) {
					ans += dp[N][j];
					cout << j << "," << dp[N][j] << " ";
				}
			}
			cout << endl;
			return ans;
		}

		bool check_prime(int k) {
			for (int i = 2; i <= sqrt(k); i++) {
				if (k % i == 0) return false;
			}
			return true;
		}
};

int main() {
	Solution sol;
	cout << sol.find(5) << endl;
}

