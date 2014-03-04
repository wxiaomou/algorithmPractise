#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
	public:
		int search(vector<vector<char>> matrix, string str) {
				int m = matrix.size();
				if (!m) return 0;
				int n = matrix[0].size();
				vector<bool> tmp(n, false);
				vector<vector<bool>> visited(m, tmp);
				int x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
				int y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						if (recur(matrix, str, visited, i, j, 0, x, y) == 1) return 1;
					}
				}
				return 0;
		}

		int recur(vector<vector<char>> &matrix, string &str, vector<vector<bool>> &visited, int i, int j, int k, int x[], int y[]) {
				int m = matrix.size();
				if (!m) return 0;
				int n = matrix[0].size();
			  if (k == str.length()) return 1;
			  if (matrix[i][j] != str[k]) return 0;
			  for (int p = 0; p < 8; p++) {
				  if ((j + x[p] >=0 && j + x[p] < n) && (i + y[p] >= 0 && i + y[p] < m)) {
						if (!visited[i + y[p]][j + x[p]]) {
							visited[i + y[p]][j + x[p]] = true;
							if (recur(matrix, str, visited, i + y[p], j + x[p], k + 1, x, y) == 1) return 1;
							visited[i + y[p]][j + x[p]] = false;
						}
					}
			  }
				return 0;
		}

};



int main() {
	vector<vector<char>> matrix;
	static const char arr[] = {'A', 'C', 'P', 'R', 'C'};
	vector<char> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	matrix.push_back(vec);
	static const char arr1[] = {'X', 'S', 'O', 'P', 'C'};
	vector<char> vec1 (arr1, arr1 + sizeof(arr) / sizeof(arr[0]) );
	matrix.push_back(vec1);
	static const char arr2[] = {'V', 'O', 'V', 'N', 'I'};
	vector<char> vec2 (arr2, arr2 + sizeof(arr) / sizeof(arr[0]) );
	matrix.push_back(vec2);
	static const char arr3[] = {'W', 'G', 'F', 'M', 'N'};
	vector<char> vec3 (arr3, arr3 + sizeof(arr) / sizeof(arr[0]) );
	matrix.push_back(vec3);
	static const char arr4[] = {'Q', 'A', 'T', 'I', 'T'};
	vector<char> vec4 (arr4, arr4 + sizeof(arr) / sizeof(arr[0]) );
	matrix.push_back(vec4);
	string str = "MICROSOFT";
	Solution sol;
	cout << sol.search(matrix, str) << endl;
}


