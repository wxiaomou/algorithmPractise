//http://www.careercup.com/question?id=3652797
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
struct node {
	int i;
	int j;
	int sum;
	node(int _i, int _j, int _sum) : i(_i), j(_j), sum(_sum) {}
};

class mycomparison
{
	public:
	 bool operator() (node &lhs, node &rhs) const
	 {
	   return  (lhs.sum < rhs.sum);
	  }
};
typedef std::priority_queue<node,std::vector<node>,mycomparison> mypq_type;

class find_sum {
public:
	int find(vector<int> A, vector<int> B, int k) {
		int m = A.size(), n = B.size();
		if (m * n < k) return -1;
		unordered_set<int> hash1;
		unordered_set<int> hash2;
		unordered_set<int> hash;
		mypq_type heap;
		int cnt = 0, i = m - 1, j = n - 1;
		heap.push(node(i, j, A[i] + A[j]));
		while (cnt < k - 1) {
			pair<int, int> tmp = make_pair(heap.top().i, heap.top().j);
			heap.pop();	
			cout << tmp.first << "," << tmp.second << ":" << A[tmp.first] + B[tmp.second] << endl;
		//	if (!(hash1.count(tmp.first - 1) && hash2.count(tmp.second))) {	
		if (hash.count(A[tmp.first - 1] +B[tmp.second]) == 0) {
				heap.push(node(tmp.first - 1, tmp.second, A[tmp.first - 1] + B[tmp.second]));
				hash1.insert(tmp.first - 1);
				hash2.insert(tmp.second);
				hash.insert(A[tmp.first - 1] + B[tmp.second]);
			}
//			if (!(hash1.count(tmp.first) && hash2.count(tmp.second - 1))) {	
		if (hash.count(A[tmp.first] + B[tmp.second - 1]) == 0) {
//			cout << "W:" <<  tmp.first << "," << tmp.second  - 1<< ":" << A[tmp.first] + B[tmp.second - 1] << endl;
				heap.push(node(tmp.first, tmp.second - 1, A[tmp.first] + B[tmp.second - 1]));
				hash1.insert(tmp.first);
				hash2.insert(tmp.second - 1);
				hash.insert(A[tmp.first] + B[tmp.second - 1]);
			}
			cnt++;
		}
		return A[heap.top().i] + B[heap.top().j];
	}

};


int main() {
	find_sum f;
	vector<int> A, B;
	int tmp;
	while (cin >> tmp && A.size() < 6) {
		A.push_back(tmp);
	}
	cout << "----------------------------------------------------------" << endl;
//	while (cin >> tmp) B.push_back(tmp);
	B.push_back(4);
	B.push_back(8);
	B.push_back(12);
	B.push_back(16);
	cout << f.find(A, B, 5) << endl;
}
