//http://blog.csdn.net/taoqick/article/details/20999895
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ctr_A {
public:
	int _max(int N) {
		vector<int> ref(N + 1, 0);
		int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 12};
		if (N < 10) return A[N];
		for (int i = 0; i <= 10; i++) ref[i] = A[i];
		int i = 10;
		while (i <= N) {
				ref[i] = ref[i - 3];
				for (int j = 4; j <= 9; j++) {
					ref[i] = max(ref[i], ref[i - j] * (j - 2));
				}
				i++;
		}
		return ref[N];
	}
};

int main() {
	ctr_A sol;
	cout << "N is " << 12 << ": " << sol._max(12) << endl; 
	cout << "N is " << 16 << ": " << sol._max(16) << endl; 
	cout << "N is " << 21 << ": " << sol._max(21) << endl; 
	cout << "N is " << 26 << ": " << sol._max(26) << endl; 
	cout << "N is " << 27 << ": " << sol._max(27) << endl; 
}

