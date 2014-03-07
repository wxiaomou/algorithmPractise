//http://community.topcoder.com/stat?c=problem_statement&pm=12918&rd=15844
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
	public:
		string equal(int A[], int B[]) {	
			vector<int> first(A, A + sizeof A / sizeof A[0]);
			vector<int> second(B, B + sizeof B / sizeof B[0]);
			sort(first.begin(), first.end());
			sort(second.begin(), second.end());
			for (int i = 0; i < first.size(); i++) {
				int tmp = lcm(first[i], first[i + 1]);
				cout << tmp << endl;
				int exits = -1;
				for (int j = i + 1; j < first.size(); j++) {
					if (tmp == first[j]) {
							exits = j;
							break;
					}
				}
				if (exits == -1) {
					first.push_back(tmp);
					sort(first.begin() + i + 1, first.end());
				}
  			if (tmp == first[i + 1]) break;
			}

   	for (int i = 0; second.size(); i++) {
				int tmp = lcm(second[i], second[i + 1]);
				int exits = -1;
				for (int j = i + 1; j < second.size(); j++) {
					if (tmp == first[j]) {
							exits = j;
							break;
					}
				}
				if (exits == -1) {
					second.push_back(tmp);
					sort(second.begin() + i + 1, second.end());
				}
//				if (tmp == second[i + 1]) break;
			}

			for (auto it = first.begin(); it != first.end(); it++)
				cout << *it << " ";
			cout << endl;

			for (auto it = second.begin(); it != second.end(); it++)
				cout << *it << " ";
			cout << endl;


			if (first.size() != second.size()) return "Not equal";
			for (int i = 0; i < first.size(); i++) {
				if (first[i] != second[i]) return "Not equal";
			}
			return "equal";
		}

		int gcd(int a, int b) {
			while(1) {
				if (!a) return b;
				b %= a;
				if (!b) return a;
				a %= b;
			}
		}

		int lcm(int a, int b) {
			int tmp = gcd(a, b);
			return tmp ? (a * b / tmp) : 0;
		}		
};


int main() {
	int A[] = {2, 3, 4, 12};
	int B[] = {2, 3, 4, 6};
	Solution sol;
	cout <<  sol.equal(A, B) << endl;

}
