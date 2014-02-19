#http://www.careercup.com/question?id=6330205329162240
#!usr/bin/env python

class Solution:
	def __init__(self):
		pass

	def addTwoArrays(self, a, b):
		m = len(a)
		n = len(b)
		maxLen = max(m, n)
		add = 0
		ret = []
		while maxLen > 0:
			x = 0
			y = 0
			if m > 0:
				x = a[m - 1]
			
			if n > 0:
				y = b[n - 1]

			tmp = x + y + add
			if tmp >= 10:
				add = 1
			else:
				add = 0

			tmp %= 10
			ret.insert(0, tmp)
			maxLen -= 1
			m -= 1
			n -= 1

		if add > 0:
			ret.insert(0, 1)

		return ret


if __name__ == "__main__":
	sol = Solution()
	a = [5, 2, 3]
	#b = [6, 4, 9]
	b = []
	print sol.addTwoArrays(a, b)

