//http://www.careercup.com/question?id=9339758
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool myfunction (pair<int, int> a, pair<int, int> b) { return ( a.second < b.second ); }
struct Node {
	int val;
	int l_cnt;
	int r_cnt;
	int root_cnt;
	Node *left, *right;
	Node (int _val) : val(_val), l_cnt(0), r_cnt(0), root_cnt(0), left(NULL), right(NULL) {}
};

class Solution {
	public:
		int find(vector<pair<int, int>> arr) {
			int n = arr.size();
			sort(arr.begin(), arr.end(), myfunction);
			vector<int> less_left(n, 0);
			get_less_left(less_left, arr);
			int _max = 0;
			for (int i = 0; i < n; i++) 
				_max = max(less_left[i] + 1, _max);
			return _max;
		}

		Node *build (Node *root, int val) {
			if (!root)
				return new Node(val);
			if (val < root->val) {
				root->l_cnt++;
				root->left = build(root->left, val);
			} else {
				root->r_cnt++;
				root->right = build(root->right, val);
			}
			return root;
		}

		int get_cnt(Node * root, int val) {
			if (!root) return 0;
			if (root->val == val) return root->l_cnt;
			if (val < root->val)
				return get_cnt(root->left, val);
			else 
				return 1 + get_cnt(root->right, val);
		}

		void get_less_left(vector<int> &less_left, vector<pair<int, int>> &arr) {
			Node *root = NULL;
			for (int i = 0; i < arr.size(); i++) {
				if (!root)
					root = build(root, arr[i].first);
				else 
				  build(root, arr[i].first);
			}
			for (int i = 0; i < arr.size(); i++) {
				less_left[i] = get_cnt(root, arr[i].first);
			}
		}
};



int main() {
	vector<pair<int, int>> arr;
	arr.push_back(make_pair(65, 100));
	arr.push_back(make_pair(70, 150));
	arr.push_back(make_pair(56, 90));
	arr.push_back(make_pair(75, 190));
	arr.push_back(make_pair(60, 95));
	arr.push_back(make_pair(68, 110));
	Solution sol;
	cout << sol.find(arr) << endl;
}
