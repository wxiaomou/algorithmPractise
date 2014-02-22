#http://lyle.smu.edu/~saad/courses/cse3358/ps5/problemset5sol.pdf  
#!usr/bin/env python

import sys
class sortedMatrix:
	def __init__(self, m, n):
		self.matrix = []
		self.m = m
		self.n = n
		i = 0
		j = 0
		tmp = []
	#	while j < n:
	#		tmp.append(sys.maxsize)
	#		j += 1
	#	while i < m:
	#		self.matrix.append(tmp)
	#		i += 1
  # wrong because each line is refert to the same tmp, so once change in one line it happends to every line !!!!!!!!!!!				
		while j < n:
			tmp.append(sys.maxint)
			j += 1
		while i < m:
			self.matrix.append(tmp[:])
			i += 1

	def __repr__(self):
		for tmp in self.matrix:
			for i in tmp:
				print i,
			print
		return ""


	def getMin(self):
		if self.matrix[0][0] == sys.maxsize:
			print "matrix is empyt"
			return
		ret = self.matrix[0][0]
		self.matrix[0][0] = sys.maxsize
		self.YoungFy(0, 0)

	def YoungFy(self, i, j):
		max_i = i
		max_j = j

		if i < self.m - 1 and self.matrix[max_i][max_j] > self.matrix[i + 1][j]:
			max_i = i + 1
			max_j = j

		if j < self.n - 1 and self.matrix[max_i][max_j] > self.matrix[i][j + 1]:
			max_i = i
			max_j = j + 1

		if max_i != i or max_j != j:
			tmp = self.matrix[max_i][max_j]
			self.matrix[max_i][max_j] = self.matrix[i][j]
			self.matrix[i][j] = tmp
			self.YoungFy(max_i, max_j)

	def insertNum(self, num):
		if self.matrix[self.m - 1][self.n -1] != sys.maxsize:
			print "matrix already full"
			return

		self.matrix[self.m - 1][self.n -1] = num

		i = self.m - 1
		j = self.n - 1
		max_i = i
		max_j = j
		threshold = sys.maxsize

		while (i > 0 or j > 0) and self.matrix[i][j] < threshold:
			tmp = self.matrix[i][j]
			self.matrix[i][j] = self.matrix[max_i][max_j]
			self.matrix[max_i][max_j] = tmp

			i = max_i
			j = max_j

			if i > 0 and self.matrix[max_i][max_j] < self.matrix[i - 1][j]:
				max_i = i - 1
				max_j = j

			if j > 0 and self.matrix[max_i][max_j] < self.matrix[i][j - 1]:
				max_i = i
				max_j = j - 1

			threshold = self.matrix[max_i][max_j]

if __name__ == "__main__":
	sol = sortedMatrix(3, 4)
	for i in xrange(1, 10):
		sol.insertNum(i)
	print str(sol)
	print sol.getMin()
	print str(sol)
