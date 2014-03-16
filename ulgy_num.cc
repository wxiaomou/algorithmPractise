//http://www.geeksforgeeks.org/ugly-numbers/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ulgy_num {
public:
	int get(int n) {
			if (n == 1) return 1;
			int ugly[n];
			ugly[0] = 1;

			int min_2, min_3, min_5;
			min_2 = 0;
			min_3 = 0;
			min_5 = 0;
			int min_2_next = 2 * ugly[min_2], min_3_next = 3 * ugly[min_3], min_5_next = 5 * ugly[min_5];

			for (int i = 1; i < n; i++) {
				int cur = min(min_2_next, min(min_3_next, min_5_next));
				ugly[i] = cur;
				if (cur == min_2_next) {
					min_2++;
					min_2_next = ugly[min_2] * 2;
				}	
				if (cur == min_3_next) {
					min_3++;
					min_3_next = ugly[min_3] * 3;
				} 
				if (cur == min_5_next){
					min_5++;
					min_5_next = ugly[min_5] * 5;
				}
			}
			return ugly[n - 1];
	}
};

int main() {
	ulgy_num u;
	cout << u.get(11) << endl;
	cout << u.get(15) << endl;
}
