//http://www.careercup.com/question?id=15382717
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Seq_digit {
public:
	int get1(int index) {
		if (index < 10) return index;
		return recur(index - 10, 10, 2) - '0';
	}
	
	char recur(int x, int base, int digit) {
		if (x < base * 10) {
			int num = x / digit + base;
//			cout << num << endl;
			char buf[100];
			snprintf(buf, sizeof(buf), "%d", num);
			return buf[x % digit];
		}
		return recur(x - base * 9 * digit, base * 10, digit + 1);
	}


	int get2(int index) {
		int digit = 0;
		int min = 0, max = -1;
		int size = 0;
		while (1) {
			digit++;
			min = max + 1;
			if (max < 0) max = 9;
			else max = max * 10 + 9;
			size = (max - min + 1) * digit;
			if (size > index) break;
			index -= size;
		}

		int num = min + index / digit;
		char buf[100];
		snprintf(buf, sizeof(buf), "%d", num);
		return buf[index % digit] - '0';
	}
 };


int main() {
Seq_digit s;
cout << "index is " << 8 << ":" << s.get1(8) << " " << s.get2(8) << endl;
cout << "index is " << 30 << ":" << s.get1(30) << " " << s.get2(30) << endl;
cout << "index is " << 31 << ":" << s.get1(31) << " " << s.get2(31) << endl;
cout << "index is " << 100 << ":" << s.get1(100) << " " << s.get2(100) << endl;
cout << "index is " << 1000 << ":" << s.get1(1000) << " " << s.get2(1000) << endl;

cout << "index is " << 10000 << ":" << s.get1(10000) << " " << s.get2(10000) << endl;
}
