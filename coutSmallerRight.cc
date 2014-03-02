#include<iostream>
#include<vector>

using namespace std;
struct Node {
	int val;
	int lcount;
	Node *left, *right;
	Node (int _val) : val(_val), lcount(0), left(NULL), right(NULL) {}
};

class Solution {
	public:
		vector<int> foo(int A[], int n) {
			if (n < 2) return vector<int>();
			Node *root = new Node(A[n - 1]);
			vector<int> ret(n, 0);
			for (int i = n - 2; i >= 0; i--) {
				int tmp = 0;
				insert(root, A[i], tmp);
				ret[i] = tmp;
			}
			return ret;
		}


		void insert(Node *root, int a, int &tmp) {
			if (root->val >= a) {
				root->lcount++;
				if (!root->left) {
					root->left = new Node(a);
				} else {
					insert(root->left, a, tmp);
				}
			} else {
				tmp += root->lcount + 1;
				if (!root->right)
					root->right = new Node(a);
				else 
					insert(root->right, a, tmp);
			}
			return;
		}
};

int main() {
	int A[8] = {4, 12, 5, 6, 1, 34, 3, 2};
	Solution sol;
	vector<int> ret = sol.foo(A, 8);
	for (auto it = ret.begin(); it != ret.end(); it ++)
		cout << *it << " ";
	cout << endl;
}
