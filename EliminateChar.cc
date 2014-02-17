#include <iostream>

using namespace std;

class Solution {
	public:
		int Eliminate(string & text) {
				int n = text.size();
				int i = 0, j = 0;
				while (j < n) {
						if (text[j] != 'b' && text[j] != 'a') {
								text[i++] = text[j++];
						} else {
								if (text[j] == 'b')
									j++;
								else if (j + 1 >= n || (j + 1 < n && text[j + 1] != 'c')) {
									text[i++] = text[j++];
								} else {
									j += 2;
								}
						}
				}
				return i;
		}
};

int main() {
	Solution sol;
	string text = "breactac";
	text = "acac";
	int len = sol.Eliminate(text);
	cout << text.substr(0, len) << endl;
	return 0;
}
