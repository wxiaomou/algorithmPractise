#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TheMatrix {
public:
	//O(n^4) Solution, tried to enable j = c - 1 to reduce to O(n^3) but failed some case need to do more work.
	int MaxArea(vector <string> board) {
		int m = board.size();
		if (!m) return 0;
		int n = board[0].size();
		
		int ret = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int min_len = 100000;
				
				for (int c = j; c < n; c++) {
					if (c > j && board[i][c] == board[i][c - 1]) {
					//	j = c - 1; // because these two col may be same at this row but they may be valid for next row.
						break;
					}
					int len = 1;
					for (int k = i + 1; k < m; k++) {
						if (board[k][c] != board[k - 1][c]) len++;
						else break;			
					}
					min_len = min(min_len, len);
					ret = max(ret, min_len * (c - j + 1));
				}			
				
			}
		}
		return ret;
	}

//Better Solution O(n^3) http://apps.topcoder.com/wiki/display/tc/SRM+610?&vote.choice=I+liked+it.&ballot.title=Editorial+feedback
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TheMatrix {
public:
	int MaxArea(vector <string> board) {
		int m = board.size();
		if (!m) return 0;
		int n = board[0].size();
		
		int ret = 1;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				int l1 = 0, l2 = 0;
				char col[n];
				if (i == j) {
					for (int k = 0; k < n; k++) col[k] = board[j][k];
				} else {
					for (int k = 0; k < n; k++) {
						if (board[j][k] == board[j - 1][k]) col[k] = 'F'; //!!!just get rid of invalid colm, in this submatrix, if two colomns value in previous row is diff, 
																		  //and in this row they diff form ther corresponsed previous value individually then they must diff this row
					}
				}
			
				for (int k = 0; k < n; k++) {
					if (col[k] == 'F') {
						l2 = 0;
					} else if ((l2 > 0) && (col[k] != col[k - 1])) {
						l2++;
					} else {
						l2 = 1;
					}	
					l1 = max(l1, l2);
				
				}
				ret = max(ret, l1 * (j - i + 1));		
			}
		}
		return ret;
	}
};
};