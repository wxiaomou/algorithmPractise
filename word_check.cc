#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	public:
		bool check(string input) {
			int n = input.length();
			if (n < 4) return false;
			vector<int> count(4, 0);
			int cur_state = 0;
			for (int i = 0; i < n; i++) {
				switch(cur_state) {
					case 0:
						if (input[i] == 'h') count[cur_state]++;
						else if (input[i] == 'i') {
							cur_state = 1;
							//count[cur_state]++;
							i--;
						} else 
							return false;
						break;
					case 1:
						if (input[i] == 'i') count[cur_state]++;
						else if (input[i] == 'r') {
							cur_state = 2;
							//count[cur_state]++;
							i--;
						} else 
							return false;
						break;
					case 2:
						if (input[i] == 'r') count[cur_state]++;
						else if (input[i] == 'e') {
							cur_state = 3;
							//count[cur_state]++;
							i--;
						} else 
							return false;
						break;
					case 4:
						if (input[i] == 'e') count[cur_state]++;
						else if (input[i] == 'h') {
							cur_state = 0;
							//count[cur_state]++;
							i--;
						} else 
							return false;
						break;
				}
			}
				if (cur_state != 3) return false;
				for (int i = 0; i < 2; i++) {
					if (count[i] != count[i + 1])
						return false;
				}
				return true;
		}
};



int main(int argc, char **argv) {
	string input = "";
	Solution sol;
	input = "hhiirreehire";
	if (sol.check(input))
		cout << input << " True" << endl;
	else
		cout << input << " False" << endl;
	input = "hhirreehire";
	if (sol.check(input))
		cout << input << " True" << endl;
	else
		cout << input << " False" << endl;
input = "hhirireehire";
	if (sol.check(input))
		cout << input << " True" << endl;
	else
		cout << input << " False" << endl;


}
