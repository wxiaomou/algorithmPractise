//http://www.careercup.com/question?id=12435684
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Gen {
public:
	vector<string> ret;
	vector<string> gen(string str) {
			ret.clear();
			if (!str.length()) return vector<string>();
			if (str.length() < 32)
				gen1(str);
			else
				gen2(str);
			return ret;
	}

	//only word for no dup
	void gen1(string str) {
			int n = str.length();
			int _max = 1 << n;
			for (int i = 1; i < _max; i++) {
				string tmp = "";
				int _i = i, j = n - 1;
				while (_i) {
					if (_i & 1) {
						tmp += str[j];
					}
					_i >>= 1;
					j--;
				}
				ret.push_back(tmp);
			}
	}

	//to handle dups
	vector<string> gen2(string str) {
		ret.clear();
		if (!str.length()) return vector<string>();
		sort(str.begin(), str.end());
		recur(str, 0, "");
		return ret;
	}

	void recur(string str, int i, string tmp) {
		if (i >= str.length()) {
			ret.push_back(tmp);
			return;
		}
		char a = str[i];
		int j = i;
		while (j < str.length() && str[j] == a) j++;
		for (int len = 0; len <= j - i; len++) {
			string t = str.substr(i, len);
			recur(str, j, tmp + t);
		}
		return;
	}
};

int main() {
	Gen g;
	string str = "abc";
	vector<string> tmp = g.gen(str);
	for (auto it = tmp.begin(); it != tmp.end(); it++) cout << *it << " ";
	cout << endl;
	str = "abababab";
	tmp = g.gen(str);
	for (auto it = tmp.begin(); it != tmp.end(); it++) cout << *it << " ";
	cout << endl;

	cout << "--------------------------------------------------" << endl;
	str = "abc";
	tmp = g.gen2(str);
	for (auto it = tmp.begin(); it != tmp.end(); it++) cout << *it << " ";
	cout << endl;
	str = "abababab";
	tmp = g.gen2(str);
	for (auto it = tmp.begin(); it != tmp.end(); it++) cout << *it << " ";
	cout << endl;

}
