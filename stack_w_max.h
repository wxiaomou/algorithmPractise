#ifndef _stack_w_max_
#define _stack_w_max_
#include <stack>
using namespace std;
class stack_w_max {
private:
	stack<int> stc;
	stack<int> stc_max;
public:
	void push(int val);
	int pop();
	int get_max();
	bool isEmpty();
	int size();
};


#endif
