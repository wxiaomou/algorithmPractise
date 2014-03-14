#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct myclass {
	  bool operator() (int i,int j) 
			{
				int a = i, b = j;
				int l1 = 0, l2 = 0;
				while (a) {
					l1 ++;
					a /= 10;
				}
				while (b) {
					l2++;
					b /= 10;
				}
				a = i * pow(10, l2) + j;
				b = j * pow(10, l1) + i;
				return (a > b);
			}
} myobject;

class concatenateNums {
public:
	void concatenate(vector<int> &S) {
		if (S.size() == 0) return;
		sort(S.begin(), S.end(), myobject);
		return;
	}
};



int main() {
	vector<int> S;
	int tmp;
	while (cin >> tmp) S.push_back(tmp);
	concatenateNums sol;
	sol.concatenate(S);
	for (auto it = S.begin(); it != S.end(); it ++) {
		cout << *it << " ";
	}
	cout << endl;
}
