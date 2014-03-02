#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
	public:
		string rotate(string str) {
			int n = str.length();
			str += str;
			int begin = 0, offset = 0;
			for (int i = 0; i < 2 * n; i++) {
				if (str[i] < str[begin]) {
					begin = i;
					offset = 0;
				} else if (str[i] == str[begin + offset]){
					offset++;
				} else if (str[i] < str[begin + offset]) {
					begin = i - offset;
					if (str[i] == str[begin])
						offset = 1;
				} else {
					offset = 0;
				}
			}
			return str.substr(begin, n);
		}
};

int main() {
	Solution sol;
	string str = "BCABDADAB";
	cout << sol.rotate(str) << endl;
}
