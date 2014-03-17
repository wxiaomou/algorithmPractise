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