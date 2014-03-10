#include<iostream>
#include<stack>
#include<climits>
#include"stack_w_max.h"
using namespace std;

void stack_w_max::push(int val) {
	stc.push(val);
	if (!stc_max.empty()) {
		stc_max.push( max(val, stc_max.top()) );
	} else {
		stc_max.push(val);
	}
}

int stack_w_max::pop() {
	stc_max.pop();
	int ret = stc.top();
	stc.pop();
	return ret;
}

int stack_w_max::get_max() {
	if (!stc_max.empty())
		return stc_max.top();
	return INT_MIN;
}

bool stack_w_max::isEmpty() {
	return stc.empty();
}

int stack_w_max::size() {
	return stc.size();
}

