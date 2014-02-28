#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Solution {
	public:
		bool check(int n) {
			if (!n || n == 1) return false;
			return ((n & 0xAAAAAAAA) == 0 && (n & (n - 1)) == 0);// first part to check it 1 at the bit of 4's power and second check if it only one bit setted.
		}

		bool judge(int n) {
			while (n) {
				if (n == 1) return true;
				if (n & 3) return false;
				n >>= 2;
			}
		}
};

int main() {
	Solution sol;
	srand (time(NULL));
	int n = rand() % 1000;
	if (sol.check(n))
		cout << n << " True" << endl;
	else 
		cout << n << " False" << endl;

	if (sol.judge(n))
		cout << n << " True" << endl;
	else 
		cout << n << " False" << endl;
  n = 64;
	if (sol.check(n))
		cout << n << " True" << endl;
	else 
		cout << n << " False" << endl;

	if (sol.judge(n))
		cout << n << " True" << endl;
	else 
		cout << n << " False" << endl;

}
