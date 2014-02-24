#!usr/bin/env python

class Solution:
	def __init__(self):
		pass

	def getNum(self, n):
		if n < 0:
			return 0

		if n == 1:
			return 1

		if n == 2:
			return 1

		matrix = self.getAssitMatrix(n - 2)

		ret = matrix[0][0] * 1 + matrix[0][1] * 1

		return ret

	def getAssitMatrix(self, n):
		if n == 1:
			return [[1, 1], [1, 0]]

		ret = self.getAssitMatrix(n / 2)
		ret = self.mulMatrix(ret, ret)
		if n % 2:
			ret = self.mulMatrix(ret, [[1, 1], [1, 0]])

		return ret
	

	def mulMatrix(self, a, b):
		tmp = [[0, 0], [0, 0]]
		tmp[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0]
		tmp[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1]
		tmp[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0]
		tmp[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1]
		return tmp

	def compare(self, n):
		if n <= 2:
			return 1

		a = 1
		b = 1
		i = 0
		while i < n - 2:
			tmp = a + b
			a = b
			b = tmp
			i += 1
		return b


if __name__ == "__main__":
	sol = Solution()
	print sol.compare(5)
	print sol.getNum(5)
	print sol.compare(18)
	print sol.getNum(18)
