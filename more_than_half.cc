//http://www.careercup.com/question?id=5104572540387328
#include<iostream>
#include<vector>

using namespace std;

class _find {
public:
	int more_than_half(vector<int> nums) {
		int n = nums.size();
		if (!n) return 0;

		int ret = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!cnt) {
				ret = nums[i];
				cnt++;
				continue;
			}
			if (nums[i] == ret) cnt++;
			else {
				cnt--;
			}
		}

		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (ret ==  nums[i]) cnt++;
		}
		if (cnt >= n / 2) return ret;
		return 0;
	}
};


int main() {
	_find f;
	vector<int> num;
	int tmp;
	while (cin >> tmp) num.push_back(tmp);
	cout << f.more_than_half(num) << endl;
}

