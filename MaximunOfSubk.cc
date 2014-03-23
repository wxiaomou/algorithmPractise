#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class MaximunOfSubk {
public:
	std::vector<int> maxk(vector<int> input, int k) {
		int n = input.size();
		if (n < k) return vector<int>();
		deque<int> q;
		int i = 0;
		std::vector<int> ret;
		for (; i < k; i++) {
			while (q.size() && input[q.back()] < input[i]) q.pop_back();
			q.push_back(i);
		}
		ret.push_back(input[q.front()]);

		for (; i < n; ++i)
		{
			while (q.size() && q.front() < i - k) q.pop_front();
			while (q.size() && input[q.back()] < input[i]) q.pop_back();
			q.push_back(i);
			ret.push_back(input[q.front()]);
		}
		return ret;
	}

};

int main() {
	cout << "here" << endl;
	MaximunOfSubk m;
	vector<int> input;
	int tmp;
	
	while (cin >> tmp) {
		input.push_back(tmp);
		
	}
	vector<int> ret = m.maxk(input, 3);
	for (auto it = ret.begin(); it != ret.end(); it++) cout << *it << " ";
	cout << endl;

}