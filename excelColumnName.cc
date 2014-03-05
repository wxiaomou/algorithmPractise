#include<iostream>
#include<string>

using namespace std;

class Solution {
	public:
		string convert(int num) {
			string ret = "";
			while (num > 0) {
				int tmp = num % 26;
				num /= 26;
				if (!tmp) {
					tmp = 26;
					num --; // "Z" is tricky here, when we met num % 26 == 0, num is divisible by 26, which means num / 26 will be 1 more which contains one 26, we shoud decrease by one
									// after num /= 26;
				}
				ret = char('A' + (tmp - 1)) + ret;
			}
			return ret;
		}
};

int main() {
	Solution sol;
	for (int i = 24; i < 30; i++) {
		cout << i << " " << sol.convert(i) << endl;
	}
	cout << 52 << " " << sol.convert(52) << endl;
}

