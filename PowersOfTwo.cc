#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

class PowersOfTwo {
	public:
		long long count(vector<long long> powers) {
			int n = powers.size();
			if (!n) return 0;
			// int ref[n];
			// memset(ref, 0, sizeof(ref));
			unordered_set<long long> hash;
			return recur(powers, 0, hash, 0);//, ref);
		}
		long long recur(vector<long long> &powers, int i, unordered_set<long long> &hash, long long tmp) { //, int ref[]) {
			int n = powers.size();
			if (i == n) {
				if (hash.count(tmp) == 0) {
					hash.insert(tmp);
					return 1;
				} else {
					return 0;
				}
			}
			//if (ref[i] > 0) return ref[i];
			recur(powers, i + 1, hash, tmp, ref) + recur(powers, i + 1, hash, tmp + powers[i], ref);
			return ref[i];
		}
		// not use ref to remember cause it will cause the judgement when (i == n) not happen, while means the count will be larger.
};
//-------------------------------------------------------------------------------------------------------------------------//
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

class PowersOfTwo {
	int a[100];
	int ref[100][100];
	public:
		/*long long count(vector<long long> powers) {
			int n = powers.size();
			if (!n) return 0;
			int ref[n];
			memset(ref, 0, sizeof(ref));
			unordered_set<long long> hash;
			return recur(powers, 0, hash, 0, ref);
		}
		long long recur(vector<long long> &powers, int i, unordered_set<long long> &hash, long long tmp, int ref[]) {
			int n = powers.size();
			if (i == n) {
				if (hash.count(tmp) == 0) {
					hash.insert(tmp);
					return 1;
				} else {
					return 0;
				}
			}
			//if (ref[i] > 0) return ref[i];
			ref[i] = recur(powers, i + 1, hash, tmp, ref) + recur(powers, i + 1, hash, tmp + powers[i], ref);
			return ref[i];
		}*/
		long long count(vector<long long> powers) {
			int n = powers.size();
			if (!n) return 0;
			memset(a, 0, sizeof(a));
			memset(ref, -1, sizeof(ref));
			for (int i = 0; i < powers.size(); i++) {
				a[log(powers[i])]++;
			}
			return recur(0, 0);
		}
		long log(long long x) {
			int ret = 0;
			while (x) {
				x /= 2;
				ret++;
			}
			return (ret - 1);
		}
		int recur(int index, int carry_from_lower) {
			if (index == 100) return 1; //because input largest could be 2^50, advance by a[index] / 2 it most reach to 100;
			int cur = a[index] + carry_from_lower;
			if (ref[index][cur] != -1) return ref[index][cur];
			//from lower to higher power, each time split to carry even enelemt to higher power of odd elements;
			//e.g. we have 4 1s, so a will be [4, 0, 0....], then we contribute to 2^1 bit we can contribut even which at most is 3 ways and we can contriute odd which is at most 2 ways
			// and recur from bit 2^1, fisrt recur we have 2 carry_from_lower the we can do the same split for even we got 2 ways which lead to 4 and 0, and for odd we have one which is 2
			// then the second recur we have only two ways which lead to 2 and 0 and plus the one element form 2^0 we can have 3 and 1, so total 5 ways 0, 1, 2, 3, 4; 
			if (cur) {
				return ref[index][cur] = recur(index + 1, cur / 2) + recur(index + 1, (cur - 1) / 2);
			} else {
				return ref[index][cur] = recur(index + 1, 0);
			}
			
			return ref[index][cur];
		}		
};
