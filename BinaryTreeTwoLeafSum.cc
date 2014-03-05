//http://www.careercup.com/question?id=9538713
#include<iostream>

using namespace std;
struct Node {
	int val;
	int Lsum;
	int Rsum;
	int root_sum;
	Node *left, *right;
	Node(int _val): val(_val), Lsum(0), Rsum(0), root_sum(0){}
};

class Solution {
	public:
	int sum;
	void fill_root_sum(Node * root, int pre) {
		if (!root) return;
		root->root_sum = pre + root->val;
		fill_root_sum(root->left, root->root_sum);
		fill_root_sum(root->right, root->root_sum);
		return;
	}
	int find(Node *root) {
		if (!root) return 0;
		sum = 0;
		recur(root);
		return sum;
	}

	int recur(Node *root) {
			if (!root) return 0;
			if (!root->left && !root->right) {
				root->Rsum = 0;
				root->Lsum = 0;
				return root->val;
			}	
			int left = recur(root->left);
			int right = recur(root->right);
			sum = max(sum, left + root->root_sum + right);
			cout << sum << endl;
			return (root->val + max(left, right));
	}
};

int main() {
	Node *H = new Node(10);
	Node *I = new Node(-2);
	Node *E = new Node(8);
	E->left = H;
	E->right = I;
	Node *D = new Node(-3);
	Node *B = new Node(-7);
	B->left = D;
	B->right = E;
	Node *F = new Node(-4);
	Node *G = new Node(9);
	Node *C = new Node(6);
	C->left = F;
	C->right = G;
	Node *A = new Node(5);
	A->left = B;
	A->right = C;
	Solution sol;
	sol.fill_root_sum(A, 0);
	cout << sol.find(A) << endl;
}
