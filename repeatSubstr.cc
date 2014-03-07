//http://www.careercup.com/question?id=6495932900179968
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;
bool myfunction (string a,  string b) { 
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i])
			return ( a[i] < b[i] );
	}
	return true;
}



class Solution {
	public:
		vector<string> find(string S, int l) {
			int n = S.length();
			if (!n || !l || n < 2 * l) return vector<string>();
			unordered_set<string> hash;
			vector<string> ret;
			for (int i = 0; i <= n - l; i++) {
				string str = S.substr(i, l);
				if (hash.count(str))
					ret.push_back(str);
				else 
					hash.insert(str);
			}
			sort(ret.begin(), ret.end());
			return ret;
		}
};

int main() {
	string s =  "ABCACBABC";
	Solution sol;
	vector<string> tmp = sol.find(s, 2);
	for (auto it = tmp.begin(); it != tmp.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

