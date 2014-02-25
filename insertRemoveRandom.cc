#include <iostream>
#include <random>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
	private:
		vector<int> vec;
		unordered_map<int, int> _map;
	public:
		void insert(int n) {
			if (_map.count(n) > 0) {
				_map[n]++;
			} else {
				_map[n] = 1;
				vec.push_back(n);
			}
		}

		void remove(int n) {
			if (_map.count(n) == 0) return;
			_map[n]--;
			if (_map[n] == 0) {
				_map.erase(n);
				auto it = vec.begin();
				for (; *it != n; it++);
				vec.erase(it);
			}
		}

		int getRandom() {
			int index = rand() % vec.size();
			return vec[index];
		}

		void print() {
			for (auto it = _map.begin(); it != _map.end(); it++) {
					for (int i = 0; i < it->second; i++)
						cout << it->first << " ";
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
