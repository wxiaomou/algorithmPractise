//http://www.careercup.com/question?id=3652797
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
class mycomparison
{
	bool reverse;
	public:
		mycomparison(const bool& revparam=false)
		    {reverse=revparam;}
	 bool operator() (const int& lhs, const int&rhs) const
	 {
	   if (reverse) return (lhs>rhs);
	   else return (lhs<rhs);
	  }
};
typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

class find_sum {
public:
	int find(vector<int> A, vector<int> B, int k) {
		int m = A.size(), n = B.size();
		if (m * n < k) return -1;
		unordered_set<pair<int, int>> hash;
		priority_queue<pair<int, int>> heap;
		int cnt = 0, i = m - 1, j = n - 1;
		heap.push(make_pair(i, j));
		while (cnt < k - 1) {
			pair<int, int> tmp = heap.top();
			heap.pop();
			heap++;
			if (hash.count(make_pair(tmp.first - 1, tmp.second)) == 0) heap.push(make_pair(tmp.first - 1, tmp.second));
			if (hash.count(make_pair(tmp.first, tmp.second - 1)) == 0) heap.push(make_pair(tmp.first, tmp.second - 1)); 
			k++;
		}
		return A[heap.top().first] + B[heap.top().second];
	}

};


int main() {
	find_sum f;
	vector<int> A, B;
	int tmp;
	while (cin >> tmp) {
		A.push_back(tmp);
	}
	cout << "----------------------------------------------------------" << endl;
	while (cin >> tmp) B.push_back(tmp);
	cout << f.find(A, B, 5) << endl;
}
