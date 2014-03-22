#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DivideByZero {
public:
	int CountNumbers(vector <int> numbers) {
		int n = numbers.size();
		unordered_set<int> hash;
		if (n < 2) return 1;
		vector<int> &S = numbers;
		for (auto it = S.begin(); it != S.end(); it++) hash.insert(*it);
		int old_len = n;
		do {
			old_len = numbers.size();
			for (int i = 0; i < old_len; i++) {
				for (int j = 0; j < old_len; j++) {
					if (numbers[j] > numbers[i]) {
						int tmp = numbers[j] / numbers[i];
						if (hash.count(tmp) == 0) {
							hash.insert(tmp);
							numbers.push_back(tmp);
						} 
					}	
				}
			}
		
		} while (numbers.size() > old_len);
		return numbers.size();
	}
};