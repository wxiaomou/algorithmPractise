#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Permutation {
public:
	vector<int> closest_nums(vector<int> A, vector<int> B) {
		int n = A.size();
		if (B.size() != n) return vector<int>();
		int i = 0;
		vector<int> ret;
		//std::vector<bool> used(n, false);
		while (i < n) {
			int j;
			bool find = false;
			for (j = 0; j < B.size(); j++) {
				if (B[j] == A[i]) {
					cout << B[j] << endl;
					find = true;
					ret.push_back(B[j]);
					B.erase(B.begin() + j);
					break;
				}
			}
			if (!find) {
				sort(B.begin(), B.end());
				if (B.back() < A[i]) {
					for (int k = B.size() - 1; k >= 0; k--) ret.push_back(B[k]);
					return get_next_permutation(ret);
				} else {
					for (int k = 0; k < B.size(); k++) {
						if (B[k] > A[i]) {
							ret.push_back(B[k]);
							B.erase(B.begin() + k);
							ret.insert(ret.end(), B.begin(), B.end());
							return ret;
						}
					}
				}
			}
			i++;
		}
		return get_next_permutation(ret);
	}

	vector<int> get_next_permutation(vector<int> v) {
		cout << "here" << endl;
		int n = v.size();
		int i = n - 1;
		while (i > 0) {
			if (v[i] > v[i - 1]) break;
			i--;
		}
		i--;
		int j = n - 1;
		while (v[j] < v[i]) j--;
		int tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
		sort(v.begin() + i + 1, v.end());
		return v;
	}
};	


int main() {
	vector<int> B{1, 6, 7, 3, 2};//2, 4, 1, 3};
	vector<int> A{6, 7, 8, 9, 1};//1, 2, 0, 4};
	// std::vector<int> _A;
	Permutation p;
	vector<int> C = p.closest_nums(A, B);
	for (auto it = C.begin(); it != C.end(); it++) cout << *it << " ";
	cout << endl;
}