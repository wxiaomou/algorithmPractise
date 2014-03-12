//http://www.careercup.com/question?id=6634738777325568
//http://www.geeksforgeeks.org/diameter-of-a-binary-tree/
#include<iostream>
#include<vector>
#include"BST_Node.h"
#include<unordered_set>
#include<unordered_map>


using namespace std;

class diameter {
	
public:
	int max_diameter2(vector<Node *> nodes) {
		int n = nodes.size();
		if (!n) return 0;
		unordered_map<Node *, vector<Node *>> hash;
		Node *root = NULL;
		for (auto it = nodes.begin(); it != nodes.end(); it++) {
			if (!(*it)->parent) root = (*it);
			else {
				if (hash.count((*it)->parent) == 0) {
					vector<Node *> tmp(1, (*it));
					hash[(*it)->parent] = tmp;
				} else {
					hash[(*it)->parent].push_back((*it));
				}
			}
		}
		int h = 0;
		return recur(root, h, hash);
	}


	int recur(Node *root, int &h, unordered_map<Node *, vector<Node *>> &hash) {
		if (hash.count(root) == 0) {
			h = 1;
			return 1;
		}
		int lh = 0, rh = 0;
		int left = recur(hash[root][0], lh, hash);
		int right = hash[root].size() > 1 ? recur(hash[root][1], rh, hash) : 0;
		h = max(lh, rh) + 1;
		return max(left, max(right, lh + rh + 1));
	}

	int max_diameter(vector<Node *> nodes) {
		int n = nodes.size();
		if (!n) return 0;
		int d = 0;
		unordered_set<Node *> hash;
		for (auto it = nodes.begin(); it != nodes.end(); it++) 
			if ((*it)->parent)
				hash.insert((*it)->parent);

		for (int i = 0; i < nodes.size(); i++) {
			Node *tmp = nodes[i];
			if (hash.count(nodes[i]) > 0) continue;
			bool updateDiameter = false;
			int h = 0;
			while (tmp) {
				h++;
				if (!updateDiameter && tmp->maxHeight > 0) { // tmp->maxHeight > 0 means this node has been visited and now we can get the daimeter. 
					d = max(d, tmp->maxHeight + h);
					updateDiameter = true;
				}
				if (tmp->maxHeight >= h)
					break;

				tmp->maxHeight = h;
				tmp = tmp->parent;

			}
		}
		return d;
	}

};


int main() {
	diameter sol;
	vector<Node *> nodes;
	Node *A = new Node(1);
	Node *B = new Node(0);
	Node *C = new Node(0);
	B->parent = A;
	C->parent = A;
	
	Node *D = new Node(0);
	D->parent = C;

	Node *E = new Node(0);
	Node *O = new Node(0);
	E->parent = B;
	O->parent = B;

	Node *F = new Node(0);
	Node *G = new Node(0);

	F->parent = E;
	G->parent = E;

	Node *P = new Node(0);
	P->parent = O;

	Node *H = new Node(0);
	H->parent = G;

	Node *Q = new Node(0);
	Node *R = new Node(0);
	Q->parent = P;
	R->parent = P;

	Node *I = new Node(0);
	Node *J = new Node(0);
	I->parent = H;
	J->parent = H;

	Node *S = new Node(0);
	S->parent = R;


	nodes.push_back(A);
	nodes.push_back(B);
	nodes.push_back(C);
	nodes.push_back(D);
	nodes.push_back(E);
	nodes.push_back(F);
	nodes.push_back(G);
	nodes.push_back(H);
	nodes.push_back(I);
	nodes.push_back(J);
	nodes.push_back(O);
	nodes.push_back(P);
	nodes.push_back(Q);
	nodes.push_back(R);
	nodes.push_back(S);

	cout << sol.max_diameter2(nodes) << endl;
}
