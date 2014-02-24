#http://www.careercup.com/question?id=15072768
#!usr/bin/env python

class C:
	def __init__(self):
		pass

	def _C(self, n):
		if n == 0:
			return []

		ret = []
		for i in xrange(1, 4):
			if i < n:
				tmp = self._C(n - i)
				#print tmp
				for it in tmp:
					it.insert(0, i)

				ret.extend(tmp)
			elif i == n:
				ret.append([i])

		return ret

	def _C2(self, n):
		if n == 0:
			return 0
		if n == 1:
			return 1
		if n == 2:
			return 2
		if n == 3:
			return 4

		L = [1, 2, 4]

		i = 0
		while i < n - 3:
			tmp = L[0] + L[1] + L[2]
			L[0] = L[1]
			L[1] = L[2]
			L[2] = tmp
			i += 1

		return L[2]

	def fast(self, n):
		if n == 0:
			return 0
		if n == 1:
			return 1
		if n == 2:
			return 2
		if n == 3:
			return 4
		
		matrix = self.getAssitMatrix(n - 3)
		ret = matrix[2][0] + 2 * matrix[2][1] + 4 * matrix[2][2]
		return ret


	def getAssitMatrix(self, n):
		if n == 1:
			return [[0, 1, 0], [0, 0, 1], [1, 1, 1]]

		ret = [[0, 1, 0], [0, 0, 1], [1, 1, 1]]
		ret = self.getAssitMatrix(n / 2)
		ret = self.mulMatrix(ret, ret)
		if n % 2:
			ret = self.mulMatrix(ret, [[0, 1, 0], [0, 0, 1], [1, 1, 1]])

		return ret
	

	def mulMatrix(self, a, b):
		tmp = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
		tmp[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0]
		tmp[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1]
		tmp[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2]
 		tmp[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0]
		tmp[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1]
		tmp[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2]
	 	tmp[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0]
		tmp[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1]
		tmp[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2]
		return tmp



if __name__ == "__main__":
	sol = C()
	print len(sol._C(7))
	print sol._C2(7)
	print sol.fast(7)

