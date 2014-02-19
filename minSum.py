#http://www.careercup.com/question?id=5678435150069760
#!usr/bin/env python
class Solution:
	def __init__(self):
		pass

	def minSum(self, array):
		if len(array) == 0:
			return 0
		if len(array) == 1:
			return array[0]
		array = sorted(array)
		a = 0
		b = 0
		for i in xrange(0, len(array)):
			if i % 2 == 1:
				a *= 10
				a += array[i]
			else:
				b *= 10
				b += array[i]

		return a + b 

if __name__ == '__main__':
	sol = Solution()
	print sol.minSum([1,1,1,1,0])
	print sol.minSum([7, 9, 1, 8, 2])
