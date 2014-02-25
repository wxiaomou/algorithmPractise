#include <iostream>
#include <random>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
	private:
		list<int> lst;
		list<int>::iterator head;
		list<int>::iterator end;
		vector<list<int>::iterator> vec;
		unordered_map<int, pair< vector<list<int>::iterator>::iterator, int> > _map;
	public:
		void insert(int n) {
			if (_map.count(n) > 0) {
				*(_map[n].first) = lst.insert( (*(_map[n].first)), n);
				cout << *(*(_map[n].first)) << " "<< n << endl;
				cout << *(*(_map[n].first) ++) << endl;
				_map[n].second++;
			} else {
				lst.push_back(n);
				end = lst.end();
				vec.push_back(--end);
				vector<list<int>::iterator>::iterator it = vec.end();
				_map[n] = make_pair(--it, 1);
			}
			head = lst.begin();
			end = lst.end();
		}

		void remove(int n) {
			if (_map.count(n) == 0) return;
			auto it = *(*_map[n].first);
			lst.remove(it);
			_map[n].second--;
			if (_map[n].second == 0) {
				vec.erase(_map[n].first);
				_map.erase(n);
			}
			head = lst.begin();
			end = lst.end();
		}

		int getRandom() {
			int index = rand() % vec.size();
			return (*(vec[index]));
		}

		void print() {
			for (auto it = head; it != end; it++) {
					cout << *it << " ";
			}
			cout << endl;
		}
};


int main() {
	Solution sol;
	sol.insert(1);
	sol.insert(2);
	sol.insert(1);
	sol.insert(2);
	sol.insert(3);
	sol.print();
	sol.insert(2);
	sol.insert(5);
	sol.insert(4);
	sol.insert(6);
	sol.print();
	cout << sol.getRandom() << endl;
}
