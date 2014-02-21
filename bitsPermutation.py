#http://www.careercup.com/question?id=5747769461440512
#graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation
#!usr/bin/env python

class Solution:
	def __init__(self):
		pass

	def nextHigh(self, x):
		_len = 1
		while x & (1 << (32 - _len)) == 0:
			_len += 1
		_len = 32 - _len
		one = -1
		zero = -1
		i = 0
		while i <= _len:
			if ((x & (1 << i)) != 0):
				if one == -1:
					one = i
			else:
				if zero == -1 and one != -1:
					zero = i

			if one != -1 and zero != -1:
				break

			i += 1

		if one == -1:
			print "invalid input"
			return

		if zero == -1:
			x |= (1 << i)
			x ^= (1 << _len)
			return x

		x ^= (1 << one)
		x |= (1 << zero)
		return x


	def nextSmall(self, x):
		_len = 1
		while x & (1 << (32 - _len)) == 0:
			_len += 1
		_len = 32 - _len
		one = -1
		zero = -1
		i = 0
		while i <= _len:
			if ((x & (1 << i)) != 0):
				if one == -1:
					if i > 0 and (x & (1 << (i - 1)) == 0):
						one = i
						zero = i - 1
						break
			#else:
			#	if zero == -1:
			#		zero = i

			#if one != -1 and zero != -1:
			#	break

			i += 1

		if zero == -1 or one == -1:
			print "invalid input"
			return

		x ^= (1 << one)
		x |= (1 << zero)
		return x


	

if __name__ == "__main__":
	sol = Solution()
	print sol.nextHigh(5)
	print sol.nextHigh(6)
	print sol.nextHigh(9)
	print sol.nextHigh(10)
	print '-------------------'
	print sol.nextSmall(12)
	print sol.nextSmall(10)
	print sol.nextSmall(6)

