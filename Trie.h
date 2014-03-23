#ifndef __Trie__
#define __Trie__

#define Alphaber_size 26
#include <vector>
#include <string>

using namespace std;
struct node {
	bool complete;
	node *children[Alphaber_size];
	node(): complete(false) {
		for (int i = 0; i < Alphaber_size; i++) {
			children[i] = NULL;
		}
	}
};

class Trie {
private:
	node *root;

public:
	Trie() {
		root = new node();
	}

	void insert(string str) {
		int n = str.length();
		if (!n) return;
		node *pcrawl = root;
		for (int i = 0; i < n; i++) {
			if (!pcrawl->children[str[i] - 'a']) {
				pcrawl->children[str[i] - 'a'] = new node();
			}
			pcrawl = pcrawl->children[str[i] - 'a'];
		}

		pcrawl->complete = true;
	}

	bool search(string str) {
		int n = str.length();
		if (!n) return true;
		node *pcrawl = root;
		for (int i = 0; i < n; i++) {
			if (!pcrawl->children[str[i] - 'a']) return false;
			pcrawl = pcrawl->children[str[i] - 'a'];
		}

		if (pcrawl && pcrawl->complete) return true;
		return false;
	}

};



#endif