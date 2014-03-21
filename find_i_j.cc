//http://www.careercup.com/question?id=11532811
//http://leetcode.com/2011/05/a-distance-maximizing-problem.html
#include <iostream>
#include <vector>
//#include <climit.h>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
	public:
		void find_i_j(vector<int> nums) {
			int n = nums.size();
			if (n < 2) return;
			int ret = 0;
			int Lmin[n], Rmax[n];
			Lmin[0] = nums[0];
			Rmax[n - 1] = nums[n - 1];
			for (int i = 1; i < n; i++) Lmin[i] = min(nums[i], Lmin[i - 1]);
			for (int i = n - 2; i >= 0; i--) Rmax[i] = max(nums[i], Rmax[i + 1]);
			int i = 0, j = 0;
			int _i = 0, _j = 0, _max = 0;
			while (i < n && j < n) {
				if (Lmin[i] < Rmax[j]) {
					if (j - i > _max) {
						_max = j - i;
						_j = j;
						_i = i;
					}
					j++;
				} else i++;
				if (i > j) j = i + 1;
			}
			cout << _i << ":" << _j << endl;
		}

		void find_i_j2(vector<int> nums) {
			int n = nums.size();
			if (n < 2) return;
			vector<int> start;
			start.push_back(0);
			int _min = nums[0];
			for (int i = 1; i < n; ++i)
			{
				_min = min(nums[i], _min);
				if (nums[i] <= _min) start.push_back(i);
			}
			int _i = 0, _j = 0;
			// cout << "size " << start.size() << endl; 
			for (int i = n - 1; i >= 0; --i)
			{
				for (auto j = start.begin(); j != start.end(); ++j)
				{
					if (*j < i) {
						if (nums[*j] < nums[i]) {
							if (i - *j > _j - _i) {
								_i = *j;
								_j = i;
							}
						}
					} else 
						break;
				}
			}
			cout << _i << ":" << _j << endl;
		}

};

int main() {
	Solution sol;
	std::vector<int> v;
	int tmp;
	while (cin >> tmp) v.push_back(tmp);
	sol.find_i_j(v);
	sol.find_i_j2(v);
}
