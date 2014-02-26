#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

struct Node {
	string val;
	bool tmp_mark;
	bool mark;
	vector<string> adjacent;

	//Node(string a_val, vector<string> tmp = vector<string>()) : val(a_val), incomeIndex(0) {} 
};

class Solution {
	private:
		vector<Node> ret;
		unordered_map<string, Node> hash;
	public:
		vector<Node> sort(vector<pair<string, string>> input) {
				//initial the graph
				for (int i = 0; i < input.size(); i++) {
					string a = input[i].first, b = input[i].second; 
					if (hash.count(a) == 0) {
						Node tmp;
						tmp.val = a;
						tmp.tmp_mark = false;
						tmp.mark = false;
						hash[a] = tmp;
					}
					if (a != b)
						hash[a].adjacent.push_back(b);
					if (hash.count(b) == 0) {
						Node tmp;
						tmp.val = b;
						tmp.tmp_mark = false;
						tmp.mark = false;
						hash[b] = tmp;
					}
				}
				visit(hash["A"]);
				visit(hash["F"]);
				return ret;
	}
	
	void visit(Node start) {
		if (start.tmp_mark) {
				cout << "ERROR not DAG" << endl;
				return; 
		}
		start.tmp_mark = true;
		for (int i = 0; i < start.adjacent.size(); i++) {
				visit(hash[start.adjacent[i]]);
		}
		start.mark = true;
		hash.erase(start.val);
		ret.insert(ret.begin(), start);
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

