//http://www.careercup.com/question?id=15071816	
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int get_random(int begin, int end, vector<int> A, int k) {
	if (begin > end) return -1;
	int x = rand() % (end - begin + 1);
	x += begin;
	sort(A.begin(), A.end());
	if (begin > A[0] || end < A.back()) return -1;
	if (!k || x < A[0]) return x;
	if (x >= A[k - 1]) return x + k;
	int i = 0;
	cout << "origin x is " << x << endl;
	while (x >= A[i] && i < k) {
		x++;
		i++;
	}
	return x;
}

int main() {
	vector<int> A;
	int tmp;
	while (cin >> tmp) A.push_back(tmp);
	cout << get_random(0, 20, A, A.size()) << endl;

}