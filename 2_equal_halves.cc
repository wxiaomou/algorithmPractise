//http://www.careercup.com/question?id=6579701673885696
#include<iostream>
#include<vector>

using namespace std;

class Solution {
	public:
		vector<int> ret;
		int memoize[100][100][100];
		vector<int> find(int arr[], int n) {
			if (!n) return ret;
			int sum = 0;
			for (int i = 0; i < n; i++) sum += arr[i];
			sum /= 2;
			memset(memoize,-1,sizeof(memoize));
			vector<int> tmp;
			dorecur(arr, n, 0, n / 2, sum, tmp);
			return ret;
		}

  	void dorecur(int arr[], int n, int pos, int left, int sum, vector<int> &tmp) {
			if (!sum && !left) {
				ret = tmp;
				return;
			} else if (sum < 0 || pos == n || !left) {
				return;
			}
			if (memoize[pos][left][sum] != -1) return;
			tmp.push_back(arr[pos]);
		  dorecur(arr, n, pos + 1, left - 1, sum - arr[pos], tmp);
			tmp.pop_back();
			dorecur(arr, n, pos + 1, left, sum, tmp);
			memoize[pos][left][sum] = 1;
			return;
		}
};

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	Solution sol;
	vector<int> ret = sol.find(arr, 12);
	for (auto it = ret.begin(); it != ret.end(); it++) {
			cout << *it << " ";
	}
	cout << endl;
}
