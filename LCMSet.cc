//http://community.topcoder.com/stat?c=problem_statement&pm=12918&rd=15844
#include<iostream>
#include<string>
#include<vector>
#include <queue>
#include <unordered_set>

using namespace std;

class mycomparison
{
	  bool reverse;
	public:
		mycomparison(const bool& revparam=true)
		{reverse=revparam;}
		bool operator() (const int& lhs, const int&rhs) const
	  {
			if (reverse) return (lhs>rhs);
			else return (lhs<rhs);
		}
};

class Solution {
	public:
		string equal(vector<long long> A, vector<long long> B) {	
			vector<long long> first;
			vector<long long> second;
			for (int i = 0; i < A.size(); i++) first.push_back((long long)A[i]);
			for (int i = 0; i < B.size(); i++) second.push_back((long long)B[i]);

			unordered_set<long long> hash;
			for (auto it = first.begin(); it != first.end(); it++) hash.insert(*it);
			gen_lcm(first, first.size(), 0, hash);
			hash.clear();
			for (auto it = second.begin(); it != second.end(); it++) hash.insert(*it);
			gen_lcm(second, second.size(), 0, hash);

			sort(first.begin(), first.end());
			sort(second.begin(), second.end());

			for (auto it = first.begin(); it != first.end(); it++)
				cout << *it << " ";
			cout << endl;

			for (auto it = second.begin(); it != second.end(); it++)
				cout << *it << " ";
			cout << endl;


			if (first.size() != second.size()) return "Not equal";
			for (int i = 0; i < first.size(); i++) {
				if (first[i] != second[i]) return "Not equal";
			}
			return "equal";
		}

		void gen_lcm(vector<long long> &input, const int &n, int i, unordered_set<long long> &hash) {
			if (i == n) return;
			int pre_n = input.size();
		  for (int k = i + 1; k < pre_n; k++) {
				int tmp = lcm(input[i], input[k]);
				if (hash.count(tmp) == 0) {
					hash.insert(tmp);
					input.push_back(tmp);
				}
			}
			gen_lcm(input, n, i + 1, hash);
		}

		long long gcd(long long a, long long b) {
			while(1) {
				if (!a) return b;
				b %= a;
				if (!b) return a;
				a %= b;
			}
		}

		long long lcm(long long a, long long b) {
			long long tmp = gcd(a, b);
			cout << tmp << endl;
			return tmp ? (a * (b / tmp)) : 0;
		}		
};


int main() {
	int A[] = {2, 3, 4, 12};
	int B[] = {2, 3, 4, 6};
	Solution sol;
	vector<int> A1(A, A + 4);
	vector<int> B1(B, B + 4);
//	cout <<  sol.equal(A1, B1) << endl;
	int C[] = {4,9};
	int D[] = {6,36};
	vector<int> C1(C, C + 2);
	vector<int> D1(D, D + 2);
//	cout << sol.equal(C1, D1) << endl;

	int E[] = {2,3,5,7,14,105};
	int F[] = {2,3,5,6,7,30,36};
	vector<int> E1(E, E + 6);
	vector<int> F1(F, F + 7);
//	cout <<  sol.equal(E1, F1) << endl;

	int G[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int H[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	vector<int> G1(G, G + 25);
	vector<int> H1(H, H + 25);
//	cout <<  sol.equal(G1, H1) << endl;

	long long I[] = {999999999,1953125,512,1000000000};
	long long J[] = {999999999,1953125,512};
	vector<long long> I1(I, I + 4);
	vector<long long> J1(J, J + 3);
	cout <<  sol.equal(I1, J1) << endl;




}
