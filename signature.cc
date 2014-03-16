//http://www.careercup.com/question?id=14912744
#include<iostream>
#include<vector>

using namespace std;

class _generate {
public:
	vector<int> gen(const string &str) {
			int n = str.length();
			if (!n) return vector<int>();
			int lasti = 1;
			vector<int> ret;
			for (int i = 0; i < n; i++) {
				if (str[i] == 'I') {
					for (int j = i + 1; j >= lasti; j--) {
						ret.push_back(j);
					}			
					lasti = i + 2;
				}
			}
			for (int j = n + 1; j >= lasti; j--) {
				ret.push_back(j);
			}
			return ret;
	}
};

int main() {
	_generate g;
	cout << "inpute dignature" << endl;
	string str;
	cin >> str;
	vector<int> tmp = g.gen(str);
	for (auto it = tmp.begin(); it != tmp.end(); it++) cout << *it << " ";
	cout << endl;
}
