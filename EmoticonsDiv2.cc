/*#include <algorithm>
#include <vector>
using namespace std;

#define MX 10000
class EmoticonsDiv2 {
	public:
		int total;
		int printSmiles(int smiles) {
			if (smiles < 2) return 0;
			vector<int> tmp(smiles + 1, MX);
			vector<vector<int>> dp(smiles + 1, tmp);
 			total = smiles;
			return 1 + get_smiles(smiles, 1, dp);
		}
		
		int get_smiles(int smiles, int cur, vector<vector<int>> &dp) {
			if (smiles == cur) return 0;
			if (smiles < 0) return MX;
			if (smiles < cur) return MX;
			
			int ans = MX;
			if (dp[smiles][cur] != MX) return dp[smiles][cur];
			
			
			if (smiles % cur == 0)
				ans = min(ans, 1 + get_smiles(smiles - cur, cur, dp));// single paste cur.
			
			int have = total - smiles + cur;
		
			ans = min(ans, 2 + get_smiles(total - have, have, dp));// copy all exiting and paste.
	
			dp[smiles][cur] = ans;
			return ans;
			
		}
	
};*/
#include <algorithm>
#include <vector>
using namespace std;

#define MX 10000
class EmoticonsDiv2 {
	public:
	int printSmiles(int smiles) {
		if (smiles < 2) return 0;
		vector<int> tmp(smiles + 1, MX);
		vector<vector<int>> ref(smiles + 1, tmp);
		dp(smiles, smiles - 1, 1, ref);
		return ref[smiles - 1][1] + 1;
	}
	
	int dp(int &total, int smiles, int cur, vector<vector<int>> &ref) {
		if (smiles == 0) return 0;
		if (smiles < 0) return MX;
		if (ref[smiles][cur] < MX) return ref[smiles][cur];
		int tmp = cur, n = 1;
		if (smiles % cur == 0) {
			while (tmp <= smiles) {
				ref[smiles][cur] = min(ref[smiles][cur], dp(total, smiles - tmp, cur, ref) + n); //ctr + v;
				tmp += cur;
				n++;
			}
		}
		int have = total - smiles;
		if(have <= smiles / 2)
			ref[smiles][cur] = min(ref[smiles][cur], dp(total, smiles - have, have, ref) + 2); // ctr + c & ctr + v;
		return ref[smiles][cur];
	}
	
};