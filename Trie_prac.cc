#include <iostream>
#include <string>
#include <vector>
#include "Trie.h"

int main() {
	Trie t;
	vector<string> input{"the", "a", "there", "these", "answer", "by", "bye", "their"};
	vector<string> search;
	string tmp;
	while (cin >> tmp) search.push_back(tmp);

	for (int i = 0; i < input.size(); i++) {
		t.insert(input[i]);
	}

	for (auto it = search.begin(); it != search.end(); it++) {
		if (t.search(*it)) {
			cout << "search for " << *it << " exsit" << endl;
		} else {
			cout << "search for " << *it << " NOT exsit" << endl;
		}
	}

}