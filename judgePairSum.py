#http://www.careercup.com/question?id=14820665
#!usr/bin/env python

class judge:
	def __init__(self):
		pass

	def is_valid(self, k, num):
		if len(num) == 0:
			return False

		count = [0] * k

		for it in num:
			count[it % k] += 1

		#if num that can be divisible by k is odd, them must be a pair that sum not divisible
		if count[0] % 2 != 0:
			return False
		#count[k / 2] cannot apply (count[i] == count[k - i]) if k is even
		if k % 2 == 0:
			if count[k / 2] != 0:
				return False
		n = len(num)
		for i in xrange(1, k):
			if count[i] != count[k - i]:
				return False

		return True


if __name__ == "__main__":
	a = judge()
	num1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
	num2 = [1, 2, 3, 4, 5, 5, 6, 7, 8, 9 ]
	print a.is_valid(5, num1)
	print a.is_valid(5, num2)
	print a.is_valid(3, num2)
