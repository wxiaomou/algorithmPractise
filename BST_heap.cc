#include<iostream>
#include<vector> 
#include<queue>

using namespace std;
struct Node {
	int bst_val;
	int heap_val;
	Node *left, *right;
	Node(int bst, int heap): bst_val(bst), heap_val(heap), left(NULL), right(NULL) {}
};

class Solution {
	public:
	Node *build(vector<pair<int, int>> input) {
		int n = input.size();
		if (n == 1) {
			return new Node(input[0].first, input[0].second);
		}
		vector<pair<int, int>> left;
		vector<pair<int, int>> right;
		int _max = 0;
		for (int i = 1; i < n; i++) {
			if (input[i].second > input[_max].second) {
				_max = i;
			}
		}

		for (int i = 0; i < n; i++) {
			if (i == _max) continue;
			if (input[i].first < input[_max].first)
				left.push_back(input[i]);
			else 
				right.push_back(input[i]);
		}
		Node *root = new Node(input[_max].first, input[_max].second);
		root->left = build(left);
		root->right = build(right);
		return root;
	}
};

int main() {
	Solution sol;
	vector<pair<int, int>> input;
	input.push_back(make_pair(12, 6));
	input.push_back(make_pair(18, 25));
	input.push_back(make_pair(19, 10));
	input.push_back(make_pair(17, 5));
	input.push_back(make_pair(16, 11));
	Node *root = sol.build(input);
	queue<Node*> Q;
	int size = 1;
	Q.push(root);

	while (Q.size()) {
		Node *tmp = Q.front();
		cout << "(" << tmp->bst_val << "," << tmp->heap_val << ") ";
		Q.pop();
		if (tmp->left)
			Q.push(tmp->left);
		if (tmp->right)
			Q.push(tmp->right);
		size--;
		if (!size) {
			size = Q.size();
			cout << endl;
		}
	}

}
