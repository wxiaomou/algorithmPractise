//http://www.careercup.com/question?id=13561671
#include<iostream>
#include<vector>
#include<stack>
#include"BST_Node.h"

using namespace std;

class merge_2_BST {
public:
	vector<int> merge(Node *root1, Node * root2) {
		if (!root1 && !root2) return vector<int> ();
		vector<int> ret;
		stack<Node *> s1, s2;
		if (root1) {
			s1.push(root1);
			while (s1.top()->left) s1.push(s1.top()->left);
		}

		if (root2) {
			s2.push(root2);
			while (s2.top()->left) s2.push(s2.top()->left);
		}

		while (s1.size() && s2.size()) {
			stack<Node *> *s = (s1.top()->val < s2.top()->val) ? &s1 : &s2;

			Node *tmp = (*s).top();
			s->pop();
			ret.push_back(tmp->val);
			if (tmp->right) {
				s->push(tmp->right);
				while(s->top()->left) s->push(s->top()->left);
			}
		}

		stack<Node *> &s = s1.size() ? s1 : s2;
		while (s.size()) {
			Node *tmp = s.top();
			s.pop();
			ret.push_back(tmp->val);
			if (tmp->right) {
				s.push(tmp->right);
				while (s.top()->left) s.push(s.top()->left);
			}
		}	
		return ret;
	}


};

int main() {
	Node *A = new Node(3);
	Node *B = new Node(1);
	Node *C = new Node(5);
	A->left = B;
	A->right = C;
	
	Node *D = new Node(4);
	Node *E = new Node(2);
	Node *F = new Node(6);
	D->left = E;
	D->right = F;

	merge_2_BST m;
	vector<int> ret = m.merge(A, D);

	for (auto it = ret.begin(); it != ret.end(); it++) cout << *it << " ";
	cout << endl;
}
