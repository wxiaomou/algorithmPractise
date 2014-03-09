//http://www.careercup.com/question?id=16049662
#include<iostream>
#include<random>
#include<queue>
#include"BST_Node.h"

using namespace std;


class Solution {
private:
	Node *root = NULL;
public:
	void insert (int val) {
		_insert(val, root);
	}
	Node * _insert (int val, Node *root) {
		if (!root) {
			root = new Node(val);
			if (!this->root) this->root = root;
			return root;
		}
		if (root->val == val) return root;
		if (root->val > val) {
			root->left_count++;
			root->left = _insert(val, root->left);
		}	else {
			root->right_count++;
			root->right = _insert(val, root->right);
		}
		return root;
	}

	void search_range(int a, int b) {
		if (a > b) return;
		do_serach_range(a, b, this->root);
	}

	int search_range_cnt(int a, int b) {
		if (a > b) return 0;
		return do_serach_range_cnt(a, b, this->root);
	}

	void do_serach_range(int a, int b, Node *root) {
		if (!root) return;
		if (root->val >= a) do_serach_range(a, b, root->left);
		if (root->val >= a && root->val <=b) cout << root->val << " ";
		if (root->val <= b) do_serach_range(a, b, root->right);
	}

	int do_serach_range_cnt(int a, int b, Node *root) {
		if (!root) return 0;
		cout << root->val << endl;
		if (root->val <= a) {
			if (root->right && root->right->val >= a) {
				cout << "return left" << endl;
				return root->right_count;
			} 
		} else if (root->val >= b) {
			if (root->left && root->left->val <= b) {
				cout << "return right" << endl;
				return root->left_count;
			} 
		}
		int l = 0;
		int r = 0;
		if (root->left && root->left->val >= a) l = do_serach_range_cnt(a, b, root->left);
		if (root->right && root->right->val <= b) r = do_serach_range_cnt(a, b, root->right);
		if (root->val >= a && root->val <= b)
			return l + r + 1;
		return l + r;
	}

	void travers() {
		queue<Node *> q;
		q.push(this->root);
		int size = q.size();
		while (q.size()) {
			Node *tmp = q.front();
			q.pop();
			size--;
			cout << tmp->val << " ";
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
			if (!size) {
				cout << endl;
				size = q.size();
			}
		}
	}		
	
	int get_Random() {
		return Random(root);
	}
	int Random(Node *root) {
		if (!root->left && !root->right) return root->val;
		int total = 0, index = 0;
		if (!root->left) {
			total = root->right_count + 1;
			index = rand() & total;
			if (index == 1) return root->val;
			return Random(root->right);
		}

		if (!root->right) {
			total = root->left_count + 1;
			index = rand() % total;
			if (index <= root->left_count)
				return Random(root->left);
			return root->val;
		}

		total = root->left_count + 1 + root->right_count;
	  index = rand() % total;
		if (index <= root->left_count)
			return Random(root->left);
		else if (index == root->left_count + 1)
			return root->val;
		else 
			return Random(root->right);
	}

};


int main() {
	Solution sol;
	for (int i = 0; i < 100; i += 3) {
		sol.insert(i);
	}
	for (int i = 2; i < 100; i += 2) {
		sol.insert(i);
	}
//	sol.travers();

	cout << "search in range 30--65 "  << endl;
	sol.search_range(30, 65);
	cout << endl;
//	cout << "search in range 30--65 " << sol.search_range_cnt(30, 65) << endl;
  cout << sol.get_Random() << endl;
  cout << sol.get_Random() << endl;
  cout << sol.get_Random() << endl;
		
}
