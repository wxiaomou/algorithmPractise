#http://www.careercup.com/question?id=5649094550749184
#!usr/bin/env python

class Solution:
	def __init__(self):
		pass

	def _max(self, num):
		if len(num) == 0:
			return 0

		ret = num[0][1]
		cur = num[0][1]

		
		for i in xrange(1, len(num)):
			if num[i][0] > num[i - 1][0]:
				cur = max(0, cur + num[i][1])
			else:
				cur = max(0, num[i][1])
			ret = max(ret, cur)

		return ret

if __name__ == "__main__":
	sol = Solution()
	print sol._max([[-3, 1], [-2, 3], [-3, 5]])
				
			
