#include<iostream>
#include<queue>
#include "stack_w_max.h"

using namespace std;

class queue_w_max {
	private:
		stack_w_max stc1;
		stack_w_max stc2;
	public:
		void push(int val) {
			stc1.push(val);
		}

		int pop() {
			if (!stc2.isEmpty()) return stc2.pop();
			while (!stc1.isEmpty()) {
				stc2.push(stc1.pop());
			}
			return stc2.pop();
		}

		int get_max() {
			return max(stc1.get_max(), stc2.get_max());
		}
};

int main() {
	queue_w_max q;
	q.push(9);
	q.push(3);
	q.push(1);
	q.push(12);
	cout << q.get_max() << endl;
	cout << "pop " << q.pop() << endl;
	cout << q.get_max() << endl;
	q.push(2);
	q.push(120);
	q.push(5);
	cout << q.get_max() << endl;
}

