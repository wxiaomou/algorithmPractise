#include <iostream>
#include <string>

using namespace std;

class leftRigntHandleDiv2 {
public:
	int count(string S) {
		int n = S.length();
		if (n < 2) return 0;
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (S[i] == 'L') continue;
			if (S[i + 1] == 'L') cnt ++;
		}
		return cnt;
	}
};

int main() {
	return 0;
}
