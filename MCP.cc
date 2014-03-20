//http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MCP {
public:
	int min_path(vector<vector<int>> cost, int m, int n) {
		int m1 = cost.size();
		if (!m1) return -1;
		int n1 = cost[0].size();
		if (m1 <= m || n1 <= n) return -1;
		vector<int> tmp(n + 1, 0);
		vector<vector<int>> matrix(m + 1, tmp);
		matrix[0][0] = cost[0][0];
		for (int i = 1; i <= m; i++) matrix[i][0] = matrix[i - 1][0] + cost[i][0];
		for (int j = 1; j <= n; j++) matrix[0][j] = matrix[0][j - 1] + cost[0][1];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
					matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + cost[i][j];
			}
		}
		return matrix[m][n];
	}
};

int main() {
	vector<int> tmp;
	vector<vector<int>> cost;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(3);
	cost.push_back(tmp);
	tmp.clear();
	tmp.push_back(4);
	tmp.push_back(8);
	tmp.push_back(2);
	tmp.push_back(2);
	cost.push_back(tmp);
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(5);
	tmp.push_back(3);
	tmp.push_back(3);
	cost.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(5);
	tmp.push_back(9);
	tmp.push_back(1);
	cost.push_back(tmp);

	MCP m;
	cout << m.min_path(cost, 2, 2) << endl;
}
