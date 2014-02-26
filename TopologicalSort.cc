#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

struct Node {
	string val;
	int incomeIndex;
	vector<string> adjacent;

	//Node(string a_val, vector<string> tmp = vector<string>()) : val(a_val), incomeIndex(0) {} 
};

class Solution {
	public:
		vector<Node> sort(vector<pair<string, string>> input) {
				unordered_map<string, Node> hash;
				queue<Node> q;
				vector<Node> ret;
				//initial the graph
				for (int i = 0; i < input.size(); i++) {
					string a = input[i].first, b = input[i].second; 
					if (hash.count(a) == 0) {
						Node tmp;
						tmp.val = a;
						tmp.incomeIndex = 0;
						hash[a] = tmp;
					}
					hash[a].adjacent.push_back(b);
					if (hash.count(b) == 0) {
						Node tmp;
						tmp.val = b;
						tmp.incomeIndex = 0;
						hash[b] = tmp;
					}
					if (a != b)
						hash[b].incomeIndex++;
				}
				//get income index 0 element
				/*for (auto it = hash.begin(); it != hash.end(); it++) {
					cout << it->first << " " << it->second.incomeIndex << endl;
					if ((*it).second.incomeIndex == 0) {
						q.push(it->second);
						hash.erase(it);
					}
				}*/
				q.push(hash["A"]);
				q.push(hash["F"]);

				while (q.size()) {
					Node tmp = q.front();
					q.pop();
					for (int i = 0; i < tmp.adjacent.size(); i++) {
						string str = tmp.adjacent[i];
						hash[str].incomeIndex--;
						if (hash.count(str) > 0 && hash[str].incomeIndex == 0) {
							q.push(hash[str]);
							hash.erase(str);
						}
					}
					ret.push_back(tmp);
				}
			return ret;
		}
};

int main() {
	Solution sol;
	vector<pair<string, string>> input;
	input.push_back(make_pair("A", "B"));
	input.push_back(make_pair("A", "D"));
	input.push_back(make_pair("B", "C"));
	input.push_back(make_pair("C", "D"));
	input.push_back(make_pair("C", "E"));
	input.push_back(make_pair("D", "E"));
	input.push_back(make_pair("F", "F"));

	vector<Node> ret = sol.sort(input);
	for (int i = 0; i < ret.size(); i++) cout << ret[i].val << " ";
	cout << endl;
	return 0;	
}

